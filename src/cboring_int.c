#include "cboring_int.h"
#include "cboring_internal.h"
#include <assert.h>

/* Check if item is an integer */
bool cboring_is_int(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cboring_get_argument(buffer, len, &argument);
    return MAJOR_TYPE(buffer) == CBORING_UNSIGNED_INTEGER ||
        MAJOR_TYPE(buffer) == CBORING_NEGATIVE_INTEGER;
}

/* Get any integer type
 * int64_t cant quite fit the range of unsigned and 
 * negative integers in CBOR, but it is close enough
 * for most use cases */
int64_t cboring_get_int(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cboring_get_argument(buffer, len, &argument);
    switch (MAJOR_TYPE(buffer)) {
    case CBORING_UNSIGNED_INTEGER:
        return argument;
    case CBORING_NEGATIVE_INTEGER:
        return -1 - (int64_t)argument;
    default:
        return 0;
    }
}

/* Encode an integer
 * Pack the value as tightly as possible to use
 * as few bytes as possible */
size_t cboring_set_int(uint8_t *buffer, size_t maxlen, int64_t val)
{
    /* Largest integer data is head + uint64_t */
    uint8_t head;
    /* Decide which major type to use */
    head = CBORING_UNSIGNED_INTEGER;
    if (val < 0) {
        head = CBORING_NEGATIVE_INTEGER;
        /* Adjust value to negative range
         * If val = INT64_MIN it will become INT64_MAX */
        val = -1 - val;
    }
    /* Integers store the value in the argument */
    return cboring_set_argument(buffer, maxlen, head, val);
}
