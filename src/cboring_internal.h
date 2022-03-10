#ifndef CBORING_INTERNAL_H
#define CBORING_INTERNAL_H

#include <stddef.h>
#include <stdint.h>

enum {
    CBORING_UNSIGNED_INTEGER,
    CBORING_NEGATIVE_INTEGER,
    CBORING_BYTE_STRING,
    CBORING_TEXT_STRING,
    CBORING_ARRAY,
    CBORING_MAP,
    CBORING_TAGGED_ITEM,
    CBORING_FLOAT_AND_SIMPLE,
};

enum {
    CBORING_FALSE = 20,
    CBORING_TRUE = 21,
    CBORING_NULL = 22,
    CBORING_UNDEFINED = 23,
    CBORING_FOLLOWING_1 = 24,
    CBORING_FOLLOWING_2,
    CBORING_FOLLOWING_4,
    CBORING_FOLLOWING_8,
    CBORING_INDEFINITE = 31,
    CBORING_STOP_CODE = 0xff,
};

/* Major type is stored in the upper 5 bits of the head
 * Takes any CBOR buffer as input and dereferences the first byte */
#define MAJOR_TYPE_OFFSET 5
#define MAJOR_TYPE(x) (*x >> MAJOR_TYPE_OFFSET)
#define ADDITIONAL_INFO_MASK 0x1f
#define ADDITIONAL_INFO(x) (*x & ADDITIONAL_INFO_MASK)

size_t cboring_getn(const uint8_t *buffer, size_t n, uint64_t *data);
size_t cboring_setn(uint8_t *buffer, size_t n, uint64_t data);
size_t cboring_get_argument(const uint8_t *buffer, size_t len, uint64_t *argument);
size_t cboring_set_argument(uint8_t *buffer, size_t maxlen, uint8_t major_type, int64_t argument);
size_t cboring_begin_indefinite(uint8_t *buffer, size_t maxlen, uint8_t major_type);
size_t cboring_end_indefinite(uint8_t *buffer, size_t maxlen);

size_t cboring_item_size(const uint8_t *buffer, size_t len);

#endif

