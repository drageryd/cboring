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
/* TODO: Magic values */
size_t cbor_get_argument(const uint8_t *buffer, size_t len, uint64_t *argument) {
    /* The initial byte has major type in upper 3 bits and
     * additional information in lower 5 bits */
    /* At least one byte in buffer */
    assert(len > 0);
    uint8_t addinf = *buffer & 0x1f;
    if (addinf < 24) {
        /* Argument is embedded in initial byte */
        *argument = (uint64_t)addinf;
        return 1;
    } else if (addinf < 28) {
        /* Additional info 24, 25, 26 and 27 loads
         * 1, 2, 4 and 8 bytes respectively */
        size_t n = 1 << (addinf - 24);
        /* At least n bytes left after initial byte */
        assert(len > n);
        return 1 + cbor_getn(buffer + 1, n, argument);
    } else if (addinf == 31) {
        /* Indefinite, set to max */
        *argument = UINT64_MAX;
        return 1;
    } else {
        /* Not well-formed */
        assert(0);
    }
}
