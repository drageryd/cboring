#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include "cboring.h"

/* 12 */
uint8_t test_uint8_small[] = {0x0C};
/* 123 */
uint8_t test_uint8[] = {0x18, 0x7B};
/* 1234 */
uint8_t test_uint16[] = {0x19, 0x04, 0xD2};
/* 123456 */
uint8_t test_uint32[] = {0x1A, 0x00, 0x01, 0xE2, 0x40};
/* 1234567890123456789 */
uint8_t test_uint64[] = {0x1B, 0x11, 0x22, 0x10, 0xF4, 0x7D, 0xE9, 0x81, 0x15};
/* -123456 */
uint8_t test_negint[] = {0x3A, 0x00, 0x01, 0xE2, 0x3F};

void test_decode(const uint8_t *buffer, size_t len, int64_t expected) {
    int64_t res = cbor_get_int(buffer, len);
    printf("This is an integer (%s) and should be %" PRId64 ": %" PRId64 " (%s)\n",
           cbor_is_int(buffer, len) ? "yes" : "no",
           expected,
           res,
           (res == expected) ? "yes" : "no");
}

void print_buffer(const uint8_t *buffer, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%c0x%02X%c",
               (i == 0) ? '[' : ' ',
               buffer[i],
               (i < len - 1) ? ',' : ']');
    }
}

void test_encode(int64_t val, const uint8_t *expected, size_t elen) {
    uint8_t buffer[256];
    size_t len = cbor_set_int(buffer, sizeof(buffer), val);
    /* Evaluate buffer */
    printf("Encoding result for %" PRId64 ": \n", val);
    printf(" Should be: ");
    print_buffer(expected, elen);
    printf("\n Result is: ");
    print_buffer(buffer, len);
    printf("\n %s\n", (elen == len && memcmp(buffer, expected, len) == 0) ? "Identical" : "Different");
}

int main()
{
    /* Decoding */
    test_decode(test_uint8_small, sizeof(test_uint8_small), 12);
    test_decode(test_uint8, sizeof(test_uint8), 123);
    test_decode(test_uint16, sizeof(test_uint16), 1234);
    test_decode(test_uint32, sizeof(test_uint32), 123456);
    test_decode(test_uint64, sizeof(test_uint64), 1234567890123456789);
    test_decode(test_negint, sizeof(test_negint), -123456);

    /* Encoding */
    test_encode(12, test_uint8_small, sizeof(test_uint8_small));
    test_encode(123, test_uint8, sizeof(test_uint8));
    test_encode(1234, test_uint16, sizeof(test_uint16));
    test_encode(123456, test_uint32, sizeof(test_uint32));
    test_encode(1234567890123456789, test_uint64, sizeof(test_uint64));
    test_encode(-123456, test_negint, sizeof(test_negint));

    return 0;
}
