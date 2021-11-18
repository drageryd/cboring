#include "cboring_string.h"
#include "cboring_internal.h"

size_t cbor_string_length(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    size_t head_len = cbor_get_argument(buffer, len, &argument);
    /* TODO: Indefenite */
    return head_len + argument;
}

/* Get any string type */
const uint8_t *cbor_get_string_handle(const uint8_t *buffer, size_t len) {
    /* Fetch argument */
    uint64_t argument;
    /* String payload starts after head */
    size_t string_start = cbor_get_argument(buffer, len, &argument);
    /* Major type in upper 3 bits of initial byte */
    switch (*buffer >> 5) {
    case 2:
        /* Byte string */
    case 3:
        /* Text string */
        return buffer + string_start;
    default:
        return 0;
    }
}

size_t cbor_get_string_length(const uint8_t *buffer, size_t len) {
    /* Fetch argument */
    uint64_t argument;
    /* String length is loaded into argument */
    cbor_get_argument(buffer, len, &argument);
    /* Major type in upper 3 bits of initial byte */
    switch (*buffer >> 5) {
    case 2:
        /* Byte string */
    case 3:
        /* Text string */
        return argument;
    default:
        return 0;
    }
}

