#include "cboring_int.h"
#include "cboring_internal.h"

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
/* TODO: Magic values */
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
