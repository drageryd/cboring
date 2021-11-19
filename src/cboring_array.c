#include "cboring_array.h"
#include "cboring_internal.h"

/* Check if item is an array */
bool cbor_is_array(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cbor_get_argument(buffer, len, &argument);
    return MAJOR_TYPE(buffer) == CBOR_ARRAY;
}
