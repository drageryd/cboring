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

enum {
    CBOR_FALSE = 20,
    CBOR_TRUE = 21,
    CBOR_NULL = 22,
    CBOR_UNDEFINED = 23,
    CBOR_FOLLOWING_1 = 24,
    CBOR_FOLLOWING_2,
    CBOR_FOLLOWING_4,
    CBOR_FOLLOWING_8,
    CBOR_INDEFINITE = 31,
    CBOR_STOP_CODE = 0xff,
};

/* Major type is stored in the upper 5 bits of the head
 * Takes any CBOR buffer as input and dereferences the first byte */
#define MAJOR_TYPE_OFFSET 5
#define MAJOR_TYPE(x) (*x >> MAJOR_TYPE_OFFSET)
#define ADDITIONAL_INFO_MASK 0x1f
#define ADDITIONAL_INFO(x) (*x & ADDITIONAL_INFO_MASK)

size_t cbor_getn(const uint8_t *buffer, size_t n, uint64_t *data);
size_t cbor_setn(uint8_t *buffer, size_t n, uint64_t data);
size_t cbor_get_argument(const uint8_t *buffer, size_t len, uint64_t *argument);
size_t cbor_set_argument(uint8_t *buffer, size_t maxlen, uint8_t major_type, int64_t argument);
size_t cbor_begin_indefinite(uint8_t *buffer, size_t maxlen, uint8_t major_type);
size_t cbor_end_indefinite(uint8_t *buffer, size_t maxlen);

size_t cbor_item_size(const uint8_t *buffer, size_t len);

#endif

