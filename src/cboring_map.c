#include "cboring_map.h"
#include "cboring_internal.h"

/* Check if item is a map */
bool cbor_is_map(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cbor_get_argument(buffer, len, &argument);
    return MAJOR_TYPE(buffer) == CBOR_MAP;
}
