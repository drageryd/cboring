#include <bits/stdint-intn.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include "cboring.h"

/* [1, 2, 3, 4, 5, 6] */
uint8_t test_array[] = {
    0x86, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06
};

/* [1, 2, 3, ["a", "b", "c"], 5, 6] */
uint8_t test_nested_array[] = {
    0x86, 0x01, 0x02, 0x03, 0x83, 0x61, 0x61,
    0x61, 0x62, 0x61, 0x63, 0x05, 0x06
};

void test_decode(const uint8_t *buffer, size_t len, size_t index) {
    printf("Item is an array (%s) of length: %zu\n",
           cboring_is_array(buffer, len) ? "yes" : "no",
           cboring_array_length(buffer, len));

    /* Get index from array */
    /* Verify that root item is an array */
    if (cboring_is_array(buffer, len)) {
        /* Get index from array */
        size_t item_offset = cboring_array_index(buffer, len, index);
        /* Index is available if offset is less than item size */
        if (item_offset < len) {
            /* Adjust item pointer and size for value */
            buffer += item_offset;
            len -= item_offset;
            /* In this example we are expecting an integer as value */
            if (cboring_is_int(buffer, len)) {
                /* We found the expected key value pair
                 * and the value is of the expected type */
                printf("Got item at index in array: %zu: %ld\n", index, cboring_get_int(buffer, len));
            }
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

void test_encode(const int64_t *array, size_t size, bool indefinite, const uint8_t *expected, size_t elen) {
    uint8_t buffer[256];
    size_t len = 0;
    /* Start array */
    if (indefinite) {
        len = cboring_begin_indefinite_array(buffer, sizeof(buffer));
    } else {
        len = cboring_begin_definite_array(buffer, sizeof(buffer), size);
    }

    /* Add contents */
    for (size_t i = 0; i < size; i++) {
        /* In a real application remember to check the return value if the set succeeded */
        len += cboring_set_int(buffer + len, sizeof(buffer) - len, array[i]);
    }

    /* End if indefinite */
    if (indefinite) {
        len += cboring_end_indefinite_array(buffer + len, sizeof(buffer) - len);
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
    test_decode(test_array, sizeof(test_array), 2);
    test_decode(test_nested_array, sizeof(test_nested_array), 4);

    int64_t a[] = {1, 2, 3, 4, 5, 6};
    test_encode(a, sizeof(a)/sizeof(a[0]), false, test_array, sizeof(test_array));
    test_encode(a, sizeof(a)/sizeof(a[0]), true, test_array, sizeof(test_array));

    return 0;
}
