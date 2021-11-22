#include "cboring_internal.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
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
