#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include "cboring.h"
#include "cboring_string.h"

/* {"a":1, "b":2} */
uint8_t test_map[] = {0xA2, 0x61, 0x61, 0x01, 0x61, 0x62, 0x02};
/* {"a": 1, "b":{"x": 123, "y": "something"}, "c": 3} */
uint8_t test_nested_map[] = {
    0xA3, 0x61, 0x61, 0x01, 0x61, 0x62, 0xA2,
    0x61, 0x78, 0x18, 0x7B, 0x61, 0x79, 0x69,
    0x73, 0x6F, 0x6D, 0x65, 0x74, 0x68, 0x69,
    0x6E, 0x67, 0x61, 0x63, 0x03
};
/* {"a": 1, "b":["x", "y", 123], "c": 3} */
uint8_t test_nested_array[] = {
    0xA3, 0x61, 0x61, 0x01, 0x61, 0x62, 0x83,
    0x61, 0x78, 0x61, 0x79, 0x18, 0x7B, 0x61,
    0x63, 0x03
};
uint8_t test_nested_array_indef[] = {
    0xBF, 0x61, 0x61, 0x01, 0x61, 0x62, 0x9F,
    0x61, 0x78, 0x61, 0x79, 0x18, 0x7B, 0xFF,
    0x61, 0x63, 0x03, 0xFF
};

void test_decode(const uint8_t *buffer, size_t len, const char *key, size_t index) {
    printf("Item is a map (%s) of length: %zu\n",
           cbor_is_map(buffer, len) ? "yes" : "no",
           cbor_map_length(buffer, len));

    /* Verify that item is a map */
    if (cbor_is_map(buffer, len)) {
        printf("Getting value at key %s\n", key);
        size_t offset = cbor_map_get(buffer, len, key);

        /* If sub object, index it */
        if (cbor_is_array(buffer + offset, len - offset)) {
            printf(" Indexing sub array at index %zu\n", index);
            offset += cbor_array_index(buffer + offset, len - offset, index);
        } else if (cbor_is_map(buffer + offset, len - offset)) {
            printf(" Indexing sub map value at index %zu\n", index);
            offset += cbor_map_index_value(buffer + offset, len - offset, index);
        }

        /* If item is of a certain type print it */
        if (cbor_is_int(buffer + offset, len - offset)) {
            printf("  Value integer: %ld\n", cbor_get_int(buffer + offset, len - offset));
        } else if (cbor_is_string(buffer + offset, len - offset)) {
            printf("  Value string: %.*s\n",
                   (int)cbor_get_string_length(buffer + offset, len - offset),
                   cbor_get_string_handle(buffer + offset, len - offset));
        }
    }
}

void print_buffer(const uint8_t *buffer, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%c0x%02X%c",
               (i == 0) ? '[' : ' ',
               buffer[i],
               (i < len - 1) ? ',' : ']');
    }
}

void test_encode(const char **keys, const int64_t *values, size_t size, bool indefinite, const uint8_t *expected, size_t elen) {
    uint8_t buffer[256];
    size_t len = 0;

    /* Start array */
    if (indefinite) {
        len = cbor_begin_indefinite_map(buffer, sizeof(buffer));
    } else {
        len = cbor_begin_definite_map(buffer, sizeof(buffer), size);
    }

    /* Add contents keys and values */
    for (size_t i = 0; i < size; i++) {
        /* In a real application remember to check the return value if the set succeeded */
        len += cbor_set_string(buffer + len, sizeof(buffer) - len, keys[i]);
        len += cbor_set_int(buffer + len, sizeof(buffer) - len, values[i]);
    }

    /* End if indefinite */
    if (indefinite) {
        len += cbor_end_indefinite_map(buffer + len, sizeof(buffer) - len);
    }
    /* Evaluate buffer */
    printf("Encoding result for array\n");
    printf(" Should be: ");
    print_buffer(expected, elen);
    printf("\n Result is: ");
    print_buffer(buffer, len);
    printf("\n %s\n", (elen == len && memcmp(buffer, expected, len) == 0) ? "Identical" : "Different");
}

int main()
{
    test_decode(test_map, sizeof(test_map), "b", 1);
    test_decode(test_nested_map, sizeof(test_nested_map), "b", 1);
    test_decode(test_nested_array, sizeof(test_nested_array), "b", 1);
    test_decode(test_nested_array_indef, sizeof(test_nested_array_indef), "b", 1);

    const char *keys[] = {"a", "b"};
    int64_t values[] = {1, 2};
    test_encode(keys, values, sizeof(values)/sizeof(values[0]), false, test_map, sizeof(test_map));
    test_encode(keys, values, sizeof(values)/sizeof(values[0]), true, test_map, sizeof(test_map));

    return 0;
}
