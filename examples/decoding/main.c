#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include "cboring.h"

/* 12 */
uint8_t test_uint8_small[] = {0x0C};
/* 123 */
uint8_t test_uint8[] = {0x18, 0x7B};
/* 1234 */
uint8_t test_uint16[] = {0x19, 0x04, 0xD2};
/* 123456 */
uint8_t test_uint32[] = {0x1A, 0x00, 0x01, 0xE2, 0x40};
/* 12345678901234567890 */
uint8_t test_uint64[] = {0x1B, 0x11, 0x22, 0x10, 0xF4, 0x7D, 0xE9, 0x81, 0x15};
/* -123456 */
uint8_t test_negint[] = {0x3A, 0x00, 0x01, 0xE2, 0x3F};
/* "Hello World!" */
uint8_t test_string[] = {0x6C, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21};
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
    printf("This should be 12: %" PRId64 "\n",
           cbor_get_int(test_uint8_small, sizeof(test_uint8_small)));
    printf("This should be 123: %" PRId64 "\n",
           cbor_get_int(test_uint8, sizeof(test_uint8)));
    printf("This should be 1234: %" PRId64 "\n",
           cbor_get_int(test_uint16, sizeof(test_uint16)));
    printf("This should be 123456: %" PRId64 "\n",
           cbor_get_int(test_uint32, sizeof(test_uint32)));
    printf("This should be 1234567890123456789: %" PRId64 "\n",
           cbor_get_int(test_uint64, sizeof(test_uint64)));
    printf("This should be -123456: %" PRId64 "\n",
           cbor_get_int(test_negint, sizeof(test_negint)));
    printf("This should be \"Hello World!\": %.*s\n",
           (int)cbor_get_string_length(test_string, sizeof(test_string)),
           cbor_get_string_handle(test_string, sizeof(test_string)));

    /* Generally these functions are a bit to generic so they should not be accessible for the user */
    cbor_print_item(test_map, sizeof(test_map), 0, "\n");
    cbor_print_item(test_nested_map, sizeof(test_nested_map), 0, "\n");
    cbor_print_item(test_nested_array, sizeof(test_nested_array), 0, "\n");
    printf("Length of nested item should be %zu: %zu\n",
           sizeof(test_nested_array),
           cbor_item_length(test_nested_array, sizeof(test_nested_array)));
    printf("Length of nested item should be %zu: %zu\n",
           sizeof(test_nested_array_indef),
           cbor_item_length(test_nested_array_indef, sizeof(test_nested_array_indef)));

    
    return 0;
}
