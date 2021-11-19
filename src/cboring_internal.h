#ifndef CBORING_INTERNAL_H
#define CBORING_INTERNAL_H

#include <stddef.h>
#include <stdint.h>

enum {
    CBOR_UNSIGNED_INTEGER,
    CBOR_NEGATIVE_INTEGER,
    CBOR_BYTE_STRING,
    CBOR_TEXT_STRING,
    CBOR_ARRAY,
    CBOR_MAP,
    CBOR_TAGGED_ITEM,
    CBOR_FLOAT_AND_SIMPLE,
};

/* Major type is stored in the upper 5 bits of the head
 * Takes any CBOR buffer as input and dereferences the first byte */
#define MAJOR_TYPE(x) (*x >> 5)

size_t cbor_getn(const uint8_t *buffer, size_t n, uint64_t *data);
size_t cbor_get_argument(const uint8_t *buffer, size_t len, uint64_t *argument);

size_t cbor_item_size(const uint8_t *buffer, size_t len);

#endif

