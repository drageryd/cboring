#include "cboring_int.h"
#include "cboring_internal.h"
#include <assert.h>

/* Check if item is an integer */
bool cbor_is_int(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cbor_get_argument(buffer, len, &argument);
    return MAJOR_TYPE(buffer) == CBOR_UNSIGNED_INTEGER ||
        MAJOR_TYPE(buffer) == CBOR_NEGATIVE_INTEGER;
}

/* Get any integer type
 * int64_t cant quite fit the range of unsigned and 
 * negative integers in CBOR, but it is close enough
 * for most use cases */
int64_t cbor_get_int(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cbor_get_argument(buffer, len, &argument);
    switch (MAJOR_TYPE(buffer)) {
    case CBOR_UNSIGNED_INTEGER:
        return argument;
    case CBOR_NEGATIVE_INTEGER:
        return -1 - argument;
    default:
        return 0;
    }
}

/* Encode an integer
 * Pack the value as tightly as possible to use
 * as few bytes as possible */
size_t cbor_set_int(uint8_t *buffer, size_t maxlen, int64_t val)
{
    /* Largest integer data is head + uint64_t */
    uint8_t head;
    /* Decide which major type to use */
    head = CBOR_UNSIGNED_INTEGER;
    if (val < 0) {
        head = CBOR_NEGATIVE_INTEGER;
        /* Adjust value to negative range
         * If val = INT64_MIN it will become INT64_MAX */
        val = -1 - val;
    }
    /* Integers store the value in the argument */
    return cbor_set_argument(buffer, maxlen, head, val);
}
