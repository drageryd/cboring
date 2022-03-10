#include "cboring_map.h"
#include "cboring_internal.h"
#include "cboring_string.h"
#include <string.h>

/* Check if item is a map */
bool cbor_is_map(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cbor_get_argument(buffer, len, &argument);
    return MAJOR_TYPE(buffer) == CBOR_MAP;
}

/* Get the number of items in a map */
size_t cbor_map_length(const uint8_t *buffer, size_t len) {
    /* The head and argument occupy some space, find where
     * the first map item starts */
    uint64_t argument;
    size_t map_offset = cbor_get_argument(buffer, len, &argument);

    /* A definite map holds the number of items in its argument */
    if (ADDITIONAL_INFO(buffer) != CBOR_INDEFINITE) {
        return argument;
    }
    /* Indefinite maps need to be iterated to know the length */
    size_t map_length = 0;
    while (*(buffer + map_offset) != CBOR_STOP_CODE) {
        map_length++;
        /* Get key size */
        map_offset += cbor_item_size(buffer + map_offset, len - map_offset);
        /* Get value size */
        map_offset += cbor_item_size(buffer + map_offset, len - map_offset);
    }
    return map_length;
}


/* Search map for key, return position of value if found */
size_t cbor_map_get(const uint8_t *buffer, size_t len, const char *key) {
    uint64_t argument;
    size_t map_offset = cbor_get_argument(buffer, len, &argument);
    const size_t map_length = cbor_map_length(buffer, len);
    for (size_t i = 0; i < map_length; i++) {
        /* Compare key */
        if (cbor_is_text_string(buffer + map_offset, len - map_offset)) {
            const char *map_key = (const char *)cbor_get_string_handle(buffer + map_offset, len - map_offset);
            const size_t map_key_length = cbor_get_string_length(buffer + map_offset, len - map_offset);
            if (map_key_length == strlen(key) && strncmp(key, map_key, map_key_length) == 0) {
                /* Keys match, return position of map value (after key) */
                return map_offset + cbor_item_size(buffer + map_offset, len - map_offset);
            }
        }
        /* Move to next key by incrementing offset past key and value */
        map_offset += cbor_item_size(buffer + map_offset, len - map_offset);
        map_offset += cbor_item_size(buffer + map_offset, len - map_offset);
    }
    /* End of loop reached if item is not found */
    return len;
}

/* Search map for nested key */
/* TODO */

/* Get map item by index */
size_t cbor_map_index_key(const uint8_t *buffer, size_t len, size_t index) {
    uint64_t argument;
    size_t map_offset = cbor_get_argument(buffer, len, &argument);
    const size_t map_length = cbor_map_length(buffer, len);
    if (index >= map_length) {
        /* Index out of range */
        return len;
    }
    /* Go past "index" number of items to get to desired item */
    for (size_t i = 0; i < index; i++) {
        /* Move to next key by incrementing offset past key and value */
        map_offset += cbor_item_size(buffer + map_offset, len - map_offset);
        map_offset += cbor_item_size(buffer + map_offset, len - map_offset);
    }
    /* End of loop reached array_offset is now at array index */
    return map_offset;
}

size_t cbor_map_index_value(const uint8_t *buffer, size_t len, size_t index) {
    size_t map_offset = cbor_map_index_key(buffer, len, index);
    /* If the key exists, the value is next to it */
    if (map_offset != len) {
        map_offset += cbor_item_size(buffer + map_offset, len - map_offset);
    }
    return map_offset;
}

/* Encode maps */
size_t cbor_begin_definite_map(uint8_t *buffer, size_t maxlen, size_t size) {
    return cbor_set_argument(buffer, maxlen, CBOR_MAP, size);
}

size_t cbor_begin_indefinite_map(uint8_t *buffer, size_t maxlen) {
    return cbor_begin_indefinite(buffer, maxlen, CBOR_MAP);
}

size_t cbor_end_indefinite_map(uint8_t *buffer, size_t maxlen) {
    return cbor_end_indefinite(buffer, maxlen);
}
