#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include "cboring.h"
#include "cboring_int.h"

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

int main()
{
    printf("This is an integer (%s) and should be 12: %" PRId64 "\n",
           cbor_is_int(test_uint8_small, sizeof(test_uint8_small)) ? "yes" : "no",
           cbor_get_int(test_uint8_small, sizeof(test_uint8_small)));
    printf("This is an integer (%s) and should be 123: %" PRId64 "\n",
           cbor_is_int(test_uint8, sizeof(test_uint8)) ? "yes" : "no",
           cbor_get_int(test_uint8, sizeof(test_uint8)));
    printf("This is an integer (%s) and should be 1234: %" PRId64 "\n",
           cbor_is_int(test_uint16, sizeof(test_uint16)) ? "yes" : "no",
           cbor_get_int(test_uint16, sizeof(test_uint16)));
    printf("This is an integer (%s) and should be 123456: %" PRId64 "\n",
           cbor_is_int(test_uint32, sizeof(test_uint32)) ? "yes" : "no",
           cbor_get_int(test_uint32, sizeof(test_uint32)));
    printf("This is an integer (%s) and should be 1234567890123456789: %" PRId64 "\n",
           cbor_is_int(test_uint64, sizeof(test_uint64)) ? "yes" : "no",
           cbor_get_int(test_uint64, sizeof(test_uint64)));
    printf("This is an integer (%s) and should be -123456: %" PRId64 "\n",
           cbor_is_int(test_negint, sizeof(test_negint)) ? "yes" : "no",
           cbor_get_int(test_negint, sizeof(test_negint)));
    return 0;
}
