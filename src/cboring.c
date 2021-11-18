#include "cboring.h"
#include "cboring_internal.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

size_t cbor_item_length(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    size_t head_len = cbor_get_argument(buffer, len, &argument);
    switch(*buffer >> 5) {
    case 0:
    case 1:
        /* Integer items are as long as head */
        return head_len;
    case 2:
    case 3:
        /* Strings */
        return cbor_string_length(buffer, len);
    case 4:
        /* Arrays */
        return cbor_array_length(buffer, len);
    case 5:
        /* Maps */
        return cbor_map_length(buffer, len);
    case 6:
    case 7:
    default:
        return head_len;
    }
}



size_t cbor_print_item(const uint8_t *buffer, size_t len, int indentation, const char *endline) {
    uint64_t argument;
    size_t total_len = cbor_get_argument(buffer, len, &argument);
    /* Major type in upper 3 bits of initial byte */
    switch(*buffer >> 5) {
    case 0:
    case 1:
        printf("%*s%" PRId64 "%s", indentation, "", cbor_get_int(buffer, len), endline);
        return total_len;
    case 2:
    case 3:
        printf("%*s%.*s%s", indentation, "",
               (int)cbor_get_string_length(buffer, len),
               cbor_get_string_handle(buffer, len),
               endline);
        return total_len + cbor_get_string_length(buffer, len);
    case 4:
        /* Map length is loaded into argument 
         * and first item comes after head */
        printf("[\n");
        for (size_t i = 0; i < argument; i++) {
            /* Print item */
            total_len += cbor_print_item(buffer + total_len, len - total_len, indentation + 2, "\n");
        }
        printf("%*s%s\n", indentation, "", "]");
        return total_len;
    case 5:
        /* Map length is loaded into argument 
         * and first item comes after head */
        printf("{\n");
        for (size_t i = 0; i < argument; i++) {
            /* Print key */
            total_len += cbor_print_item(buffer + total_len, len - total_len, indentation + 2, ": ");
            /* Print value */
            total_len += cbor_print_item(buffer + total_len, len - total_len, indentation + 2, "\n");
        }
        printf("%*s%s\n", indentation, "", "}");
        return total_len;
    default:
        return 0;
    }
}
