#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include "cboring.h"

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


int main()
{
    /* Generally these functions are a bit to generic so they should not be accessible for the user */
    cboring_print_item(test_map, sizeof(test_map), 0, "\n");
    cboring_print_item(test_nested_map, sizeof(test_nested_map), 0, "\n");
    cboring_print_item(test_nested_array, sizeof(test_nested_array), 0, "\n");
    printf("Length of nested item should be %zu: %zu\n",
           sizeof(test_nested_array),
           cboring_item_length(test_nested_array, sizeof(test_nested_array)));
    printf("Length of nested item should be %zu: %zu\n",
           sizeof(test_nested_array_indef),
           cboring_item_length(test_nested_array_indef, sizeof(test_nested_array_indef)));
    
    return 0;
}
