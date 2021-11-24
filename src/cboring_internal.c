#include "cboring_internal.h"
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

/* Fetch n network endian bytes
 * In most cases a 64 bit value is too big but to handle
 * every case the biggest number loaded is 8 bytes 
 * Return value: bytes read*/
size_t cbor_getn(const uint8_t *buffer, size_t n, uint64_t *data) {
    *data = 0;
    for (size_t i = 0; i < n; i++) {
        *data = (*data << 8) | *(buffer++);
    }
    return n;
}

/* Store n network endian bytes
 * Return value: bytes loaded */
size_t cbor_setn(uint8_t *buffer, size_t n, uint64_t data) {
    /* Start at end of buffer beyond where lower byte is stored */
    buffer += n;
    for (size_t i = 0; i < n; i++) {
        buffer--;
        *buffer = data & 0xff;
        data >>= 8;
    }
    return n;
}

/* Get argument from head
 * This can be embedded in the first byte or
 * in the following 1, 2, 4 or 8 bytes
 * Return value: length of head */
size_t cbor_get_argument(const uint8_t *buffer, size_t len, uint64_t *argument) {
    /* The initial byte has major type in upper 3 bits and
     * additional information in lower 5 bits */
    /* At least one byte in buffer */
    assert(len > 0);
    uint8_t addinf = ADDITIONAL_INFO(buffer);
    if (addinf < CBOR_FOLLOWING_1) {
        /* Argument is embedded in initial byte */
        *argument = (uint64_t)addinf;
        return 1;
    } else if (addinf <= CBOR_FOLLOWING_8) {
        /* Additional info 24, 25, 26 and 27 loads
         * 1, 2, 4 and 8 bytes respectively */
        size_t n = 1 << (addinf - CBOR_FOLLOWING_1);
        /* At least n bytes left after initial byte */
        assert(len > n);
        return 1 + cbor_getn(buffer + 1, n, argument);
    } else if (addinf == CBOR_INDEFINITE) {
        /* Indefinite, set to max */
        *argument = UINT64_MAX;
        return 1;
    } else {
        /* Not well-formed */
        assert(0);
    }
}

/* Set argument
 * This can be embedded in the first byte or
 * in the following 1, 2, 4 or 8 bytes 
 * Return value: length of head */
size_t cbor_set_argument(uint8_t *buffer, size_t maxlen, uint8_t major_type, int64_t argument) {
    /* Shift major type up */
    major_type <<= MAJOR_TYPE_OFFSET;

    /* Decide where the value should be stored
     * < 24 fits in the head additional information */
    size_t additional_bytes = 0;
    if (argument < CBOR_FOLLOWING_1) {
        major_type |= (uint8_t)argument & ADDITIONAL_INFO_MASK;
    }
    else if (argument <= UINT8_MAX) {
        additional_bytes = 1;
        major_type |= CBOR_FOLLOWING_1 & ADDITIONAL_INFO_MASK;
    } else if (argument <= UINT16_MAX) {
        additional_bytes = 2;
        major_type |= CBOR_FOLLOWING_2 & ADDITIONAL_INFO_MASK;
    } else if (argument <= UINT32_MAX) {
        additional_bytes = 4;
        major_type |= CBOR_FOLLOWING_4 & ADDITIONAL_INFO_MASK;
    } else {
        additional_bytes = 8;
        major_type |= CBOR_FOLLOWING_8 & ADDITIONAL_INFO_MASK;
    }

    /* Is the buffer large enough for the head + additional data */
    if (maxlen < additional_bytes + 1) {
        return 0;
    }

    /* Store head and data */
    *buffer = major_type;
    return cbor_setn(buffer + 1, additional_bytes, (uint64_t)argument) + 1;
}

static size_t cbor_string_size(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    size_t head_len = cbor_get_argument(buffer, len, &argument);
    /* TODO: Indefenite */
    return head_len + argument;
}

static size_t cbor_map_size(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    size_t item_len = cbor_get_argument(buffer, len, &argument);
    /* Map length is loaded into argument
     * and first item comes after head */
    for (size_t i = 0; i < argument; i++) {
        if (argument == UINT64_MAX && *(buffer + item_len) == 0xff) {
            item_len += 1;
            break;
        }
        item_len += cbor_item_size(buffer + item_len, len - item_len);
        item_len += cbor_item_size(buffer + item_len, len - item_len);
    }
    return item_len;
}

static size_t cbor_array_size(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    size_t item_len = cbor_get_argument(buffer, len, &argument);
    /* Array length is loaded into argument
     * and first item comes after head */
    for (size_t i = 0; i < argument; i++) {
        if (argument == UINT64_MAX && *(buffer + item_len) == 0xff) {
            item_len += 1;
            break;
        }
        item_len += cbor_item_size(buffer + item_len, len - item_len);
    }
    return item_len;
}


/* How many bytes does an item consume */
size_t cbor_item_size(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    size_t head_len = cbor_get_argument(buffer, len, &argument);
    switch(MAJOR_TYPE(buffer)) {
    case CBOR_UNSIGNED_INTEGER:
    case CBOR_NEGATIVE_INTEGER:
        return head_len;
    case CBOR_BYTE_STRING:
    case CBOR_TEXT_STRING:
        return cbor_string_size(buffer, len);
    case CBOR_ARRAY:
        return cbor_array_size(buffer, len);
    case CBOR_MAP:
        return cbor_map_size(buffer, len);
    case CBOR_TAGGED_ITEM:
    case CBOR_FLOAT_AND_SIMPLE:
        /* TODO */
    default:
        return head_len;
    }
}
