#include "cboring.h"
#include "cboring_internal.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

size_t cboring_item_length(const uint8_t *buffer, size_t len) {
    return cboring_item_size(buffer, len);
}


size_t cboring_print_item(const uint8_t *buffer, size_t len, int indentation, const char *endline) {
    uint64_t argument;
    size_t total_len = cboring_get_argument(buffer, len, &argument);
    /* Major type in upper 3 bits of initial byte */
    switch(*buffer >> 5) {
    case 0:
    case 1:
        printf("%*s%" PRId64 "%s", indentation, "", cboring_get_int(buffer, len), endline);
        return total_len;
    case 2:
    case 3:
        printf("%*s%.*s%s", indentation, "",
               (int)cboring_get_string_length(buffer, len),
               cboring_get_string_handle(buffer, len),
               endline);
        return total_len + cboring_get_string_length(buffer, len);
    case 4:
        /* Map length is loaded into argument 
         * and first item comes after head */
        printf("[\n");
        for (size_t i = 0; i < argument; i++) {
            /* Print item */
            total_len += cboring_print_item(buffer + total_len, len - total_len, indentation + 2, "\n");
        }
        printf("%*s%s\n", indentation, "", "]");
        return total_len;
    case 5:
        /* Map length is loaded into argument 
         * and first item comes after head */
        printf("{\n");
        for (size_t i = 0; i < argument; i++) {
            /* Print key */
            total_len += cboring_print_item(buffer + total_len, len - total_len, indentation + 2, ": ");
            /* Print value */
            total_len += cboring_print_item(buffer + total_len, len - total_len, indentation + 2, "\n");
        }
        printf("%*s%s\n", indentation, "", "}");
        return total_len;
    default:
        return 0;
    }
}
