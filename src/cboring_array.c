#include "cboring_array.h"
#include "cboring_internal.h"

/* Check if item is an array */
bool cboring_is_array(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cboring_get_argument(buffer, len, &argument);
    return MAJOR_TYPE(buffer) == CBORING_ARRAY;
}

/* Get the number of items in an array */
size_t cboring_array_length(const uint8_t *buffer, size_t len) {
    /* The head and argument occupy some space, find where
     * the first map item starts */
    uint64_t argument;
    size_t array_offset = cboring_get_argument(buffer, len, &argument);

    /* A definite array holds the number of items in its argument */
    if (ADDITIONAL_INFO(buffer) != CBORING_INDEFINITE) {
        return argument;
    }
    /* Indefinite arrays need to be iterated to know the length */
    size_t array_length = 0;
    while (*(buffer + array_offset) != CBORING_STOP_CODE) {
        array_length++;
        /* Get item size */
        array_offset += cboring_item_size(buffer + array_offset, len - array_offset);
    }
    return array_length;
}

/* Get item at index from array */
size_t cboring_array_index(const uint8_t *buffer, size_t len, size_t index) {
    uint64_t argument;
    size_t array_offset = cboring_get_argument(buffer, len, &argument);
    const size_t array_length = cboring_array_length(buffer, len);
    if (index >= array_length) {
        /* Index out of range */
        return len;
    }
    /* Go past "index" number of items to get to desired item */
    for (size_t i = 0; i < index; i++) {
        /* Move to next key by incrementing offset past items */
        array_offset += cboring_item_size(buffer + array_offset, len - array_offset);
    }
    /* End of loop reached array_offset is now at array index */
    return array_offset;
}

/* Encode arrays */
size_t cboring_begin_definite_array(uint8_t *buffer, size_t maxlen, size_t size) {
    return cboring_set_argument(buffer, maxlen, CBORING_ARRAY, size);
}

size_t cboring_begin_indefinite_array(uint8_t *buffer, size_t maxlen) {
    return cboring_begin_indefinite(buffer, maxlen, CBORING_ARRAY);
}

size_t cboring_end_indefinite_array(uint8_t *buffer, size_t maxlen) {
    return cboring_end_indefinite(buffer, maxlen);
}
