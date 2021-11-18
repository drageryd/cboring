#include "cboring_int.h"
#include "cboring_internal.h"

#include <stdio.h>

/* Check if item is an integer */
bool cbor_is_int(const uint8_t *buffer, size_t len) {
    /* TODO */
    printf("Check if %p(%zu) is an integer\n", buffer, len);
    return true;
}

/* Get any integer type
 * int64_t cant quite fit the range of unsigned and 
 * negative integers in CBOR, but it is close enough
 * for most use cases */
/* TODO: Magic values */
int64_t cbor_get_int(const uint8_t *buffer, size_t len) {
    /* Fetch argument */
    uint64_t argument;
    cbor_get_argument(buffer, len, &argument);
    /* Major type in upper 3 bits of initial byte */
    switch (*buffer >> 5) {
    case 0:
        /* Unsigned integer */
        return argument;
    case 1:
        /* Negative integer */
        return -1 - argument;
    default:
        return 0;
    }
}
