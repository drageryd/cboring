#include "cboring_map.h"
#include "cboring_internal.h"

#include <stdio.h>

/* Check if item is a map */
bool cbor_is_map(const uint8_t *buffer, size_t len) {
    /* TODO */
    printf("Check if %p(%zu) is an integer\n", buffer, len);
    return true;
}

/* Maps contain cbor items so the generic item length function
 *  is forward declared here */
extern size_t cbor_item_length(const uint8_t *buffer, size_t len);

size_t cbor_map_length(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    size_t item_len = cbor_get_argument(buffer, len, &argument);
    /* Map length is loaded into argument 
     * and first item comes after head */
    for (size_t i = 0; i < argument; i++) {
        if (argument == UINT64_MAX && *(buffer + item_len) == 0xff) {
            item_len += 1;
            break;
        }
        item_len += cbor_item_length(buffer + item_len, len - item_len);
        item_len += cbor_item_length(buffer + item_len, len - item_len);
    }
    return item_len;
}
