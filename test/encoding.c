/* 
 * This is an auto-generated file so edit with caution
 * It creates decode tests from the cbor test-vectors repo
 * url: https://github.com/cbor/test-vectors
 *
 * Note: cboring does not support integers with the highest bit set
 *       for example uint64_t 0xFFFFFFFFFFFFFFFF will result in -1
 *       which is not what is desired.
 *
 * Usage
 * Compile this file, include the header file and call test_encode
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "unity.h"
#include "cboring.h"

/* Implement this function so that it populates dest with the diagnostics
 * notation of the decoded hex */
extern size_t decode(const uint8_t *hex, size_t hex_len, char *dest, size_t dest_len);

static void print_buffer(const uint8_t *buffer, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%c0x%02X%c",
               (i == 0) ? '[' : ' ',
               buffer[i],
               (i < len - 1) ? ',' : ']');
    }
}

void encode_test_000(void) {
    const uint8_t hex[] = {0x00};
    const char *diag = "0";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 000\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_001(void) {
    const uint8_t hex[] = {0x01};
    const char *diag = "1";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 001\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 1);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_002(void) {
    const uint8_t hex[] = {0x0a};
    const char *diag = "10";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 002\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 10);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_003(void) {
    const uint8_t hex[] = {0x17};
    const char *diag = "23";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 003\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 23);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_004(void) {
    const uint8_t hex[] = {0x18, 0x18};
    const char *diag = "24";
    uint8_t buffer[2];
    size_t len = 0;
    printf("\nEncode test 004\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 24);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_005(void) {
    const uint8_t hex[] = {0x18, 0x19};
    const char *diag = "25";
    uint8_t buffer[2];
    size_t len = 0;
    printf("\nEncode test 005\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 25);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_006(void) {
    const uint8_t hex[] = {0x18, 0x64};
    const char *diag = "100";
    uint8_t buffer[2];
    size_t len = 0;
    printf("\nEncode test 006\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 100);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_007(void) {
    const uint8_t hex[] = {0x19, 0x03, 0xe8};
    const char *diag = "1000";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 007\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 1000);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_008(void) {
    const uint8_t hex[] = {0x1a, 0x00, 0x0f, 0x42, 0x40};
    const char *diag = "1000000";
    uint8_t buffer[5];
    size_t len = 0;
    printf("\nEncode test 008\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 1000000);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_009(void) {
    const uint8_t hex[] = {0x1b, 0x00, 0x00, 0x00, 0xe8, 0xd4, 0xa5, 0x10, 0x00};
    const char *diag = "1000000000000";
    uint8_t buffer[9];
    size_t len = 0;
    printf("\nEncode test 009\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 1000000000000);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_010(void) {
    const uint8_t hex[] = {0x1b, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    const char *diag = "9223372036854775807";
    uint8_t buffer[9];
    size_t len = 0;
    printf("\nEncode test 010\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 9223372036854775807);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_011(void) {
    const uint8_t hex[] = {0xc2, 0x49, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const char *diag = "18446744073709551616";
    uint8_t buffer[11];
    size_t len = 0;
    printf("\nEncode test 011\nInput: %s\n", diag);
    len += cbor_set_null(buffer + len, sizeof(buffer) - len);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_012(void) {
    const uint8_t hex[] = {0x3b, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe};
    const char *diag = "-9223372036854775807";
    uint8_t buffer[9];
    size_t len = 0;
    printf("\nEncode test 012\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, -9223372036854775807);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_013(void) {
    const uint8_t hex[] = {0xc3, 0x49, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const char *diag = "-18446744073709551617";
    uint8_t buffer[11];
    size_t len = 0;
    printf("\nEncode test 013\nInput: %s\n", diag);
    len += cbor_set_null(buffer + len, sizeof(buffer) - len);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_014(void) {
    const uint8_t hex[] = {0x20};
    const char *diag = "-1";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 014\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, -1);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_015(void) {
    const uint8_t hex[] = {0x29};
    const char *diag = "-10";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 015\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, -10);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_016(void) {
    const uint8_t hex[] = {0x38, 0x63};
    const char *diag = "-100";
    uint8_t buffer[2];
    size_t len = 0;
    printf("\nEncode test 016\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, -100);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_017(void) {
    const uint8_t hex[] = {0x39, 0x03, 0xe7};
    const char *diag = "-1000";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 017\nInput: %s\n", diag);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, -1000);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_018(void) {
    const uint8_t hex[] = {0xf9, 0x00, 0x00};
    const char *diag = "0.0";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 018\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 0.0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_019(void) {
    const uint8_t hex[] = {0xf9, 0x80, 0x00};
    const char *diag = "-0.0";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 019\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, -0.0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_020(void) {
    const uint8_t hex[] = {0xf9, 0x3c, 0x00};
    const char *diag = "1.0";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 020\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 1.0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_021(void) {
    const uint8_t hex[] = {0xfb, 0x3f, 0xf1, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9a};
    const char *diag = "1.1";
    uint8_t buffer[9];
    size_t len = 0;
    printf("\nEncode test 021\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 1.1);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_022(void) {
    const uint8_t hex[] = {0xf9, 0x3e, 0x00};
    const char *diag = "1.5";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 022\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 1.5);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_023(void) {
    const uint8_t hex[] = {0xf9, 0x7b, 0xff};
    const char *diag = "65504.0";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 023\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 65504.0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_024(void) {
    const uint8_t hex[] = {0xfa, 0x47, 0xc3, 0x50, 0x00};
    const char *diag = "100000.0";
    uint8_t buffer[5];
    size_t len = 0;
    printf("\nEncode test 024\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 100000.0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_025(void) {
    const uint8_t hex[] = {0xfa, 0x7f, 0x7f, 0xff, 0xff};
    const char *diag = "3.4028234663852886e+38";
    uint8_t buffer[5];
    size_t len = 0;
    printf("\nEncode test 025\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 3.4028234663852886e+38);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_026(void) {
    const uint8_t hex[] = {0xfb, 0x7e, 0x37, 0xe4, 0x3c, 0x88, 0x00, 0x75, 0x9c};
    const char *diag = "1e+300";
    uint8_t buffer[9];
    size_t len = 0;
    printf("\nEncode test 026\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 1e+300);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_027(void) {
    const uint8_t hex[] = {0xf9, 0x00, 0x01};
    const char *diag = "5.960464477539063e-08";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 027\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 5.960464477539063e-08);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_028(void) {
    const uint8_t hex[] = {0xf9, 0x04, 0x00};
    const char *diag = "6.103515625e-05";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 028\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, 6.103515625e-05);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_029(void) {
    const uint8_t hex[] = {0xf9, 0xc4, 0x00};
    const char *diag = "-4.0";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 029\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, -4.0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_030(void) {
    const uint8_t hex[] = {0xfb, 0xc0, 0x10, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66};
    const char *diag = "-4.1";
    uint8_t buffer[9];
    size_t len = 0;
    printf("\nEncode test 030\nInput: %s\n", diag);
    len += cbor_set_float(buffer + len, sizeof(buffer) - len, -4.1);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_031(void) {
    const uint8_t hex[] = {0xf4};
    const char *diag = "false";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 031\nInput: %s\n", diag);
    len += cbor_set_bool(buffer + len, sizeof(buffer) - len, false);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_032(void) {
    const uint8_t hex[] = {0xf5};
    const char *diag = "true";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 032\nInput: %s\n", diag);
    len += cbor_set_bool(buffer + len, sizeof(buffer) - len, true);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_033(void) {
    const uint8_t hex[] = {0xf6};
    const char *diag = "null";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 033\nInput: %s\n", diag);
    len += cbor_set_null(buffer + len, sizeof(buffer) - len);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_034(void) {
    const uint8_t hex[] = {0x60};
    const char *diag = "\"\"";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 034\nInput: %s\n", diag);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_035(void) {
    const uint8_t hex[] = {0x61, 0x61};
    const char *diag = "\"a\"";
    uint8_t buffer[2];
    size_t len = 0;
    printf("\nEncode test 035\nInput: %s\n", diag);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "a");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_036(void) {
    const uint8_t hex[] = {0x64, 0x49, 0x45, 0x54, 0x46};
    const char *diag = "\"IETF\"";
    uint8_t buffer[5];
    size_t len = 0;
    printf("\nEncode test 036\nInput: %s\n", diag);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "IETF");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_037(void) {
    const uint8_t hex[] = {0x62, 0x22, 0x5c};
    const char *diag = "\"\\\"\\\\\"";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 037\nInput: %s\n", diag);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "\"\\");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_038(void) {
    const uint8_t hex[] = {0x62, 0xc3, 0xbc};
    const char *diag = "\"\\u00fc\"";
    uint8_t buffer[3];
    size_t len = 0;
    printf("\nEncode test 038\nInput: %s\n", diag);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "ü");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_039(void) {
    const uint8_t hex[] = {0x63, 0xe6, 0xb0, 0xb4};
    const char *diag = "\"\\u6c34\"";
    uint8_t buffer[4];
    size_t len = 0;
    printf("\nEncode test 039\nInput: %s\n", diag);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "水");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_040(void) {
    const uint8_t hex[] = {0x64, 0xf0, 0x90, 0x85, 0x91};
    const char *diag = "\"\\ud800\\udd51\"";
    uint8_t buffer[5];
    size_t len = 0;
    printf("\nEncode test 040\nInput: %s\n", diag);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "𐅑");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_041(void) {
    const uint8_t hex[] = {0x80};
    const char *diag = "[]";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 041\nInput: %s\n", diag);
    len += cbor_begin_definite_array(buffer + len, sizeof(buffer) - len, 0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_042(void) {
    const uint8_t hex[] = {0x83, 0x01, 0x02, 0x03};
    const char *diag = "[1, 2, 3]";
    uint8_t buffer[4];
    size_t len = 0;
    printf("\nEncode test 042\nInput: %s\n", diag);
    len += cbor_begin_definite_array(buffer + len, sizeof(buffer) - len, 3);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 1);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 3);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_043(void) {
    const uint8_t hex[] = {0x83, 0x01, 0x82, 0x02, 0x03, 0x82, 0x04, 0x05};
    const char *diag = "[1, [2, 3], [4, 5]]";
    uint8_t buffer[8];
    size_t len = 0;
    printf("\nEncode test 043\nInput: %s\n", diag);
    len += cbor_begin_definite_array(buffer + len, sizeof(buffer) - len, 3);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 1);
    len += cbor_begin_definite_array(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 3);
    len += cbor_begin_definite_array(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 4);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 5);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_044(void) {
    const uint8_t hex[] = {0x98, 0x19, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x18, 0x18, 0x19};
    const char *diag = "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]";
    uint8_t buffer[29];
    size_t len = 0;
    printf("\nEncode test 044\nInput: %s\n", diag);
    len += cbor_begin_definite_array(buffer + len, sizeof(buffer) - len, 25);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 1);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 3);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 4);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 5);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 6);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 7);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 8);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 9);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 10);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 11);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 12);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 13);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 14);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 15);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 16);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 17);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 18);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 19);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 20);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 21);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 22);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 23);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 24);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 25);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_045(void) {
    const uint8_t hex[] = {0xa0};
    const char *diag = "{}";
    uint8_t buffer[1];
    size_t len = 0;
    printf("\nEncode test 045\nInput: %s\n", diag);
    len += cbor_begin_definite_map(buffer + len, sizeof(buffer) - len, 0);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_046(void) {
    const uint8_t hex[] = {0xa2, 0x61, 0x61, 0x01, 0x61, 0x62, 0x82, 0x02, 0x03};
    const char *diag = "{\"a\": 1, \"b\": [2, 3]}";
    uint8_t buffer[9];
    size_t len = 0;
    printf("\nEncode test 046\nInput: %s\n", diag);
    len += cbor_begin_definite_map(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "a");
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 1);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "b");
    len += cbor_begin_definite_array(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_int(buffer + len, sizeof(buffer) - len, 3);
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_047(void) {
    const uint8_t hex[] = {0x82, 0x61, 0x61, 0xa1, 0x61, 0x62, 0x61, 0x63};
    const char *diag = "[\"a\", {\"b\": \"c\"}]";
    uint8_t buffer[8];
    size_t len = 0;
    printf("\nEncode test 047\nInput: %s\n", diag);
    len += cbor_begin_definite_array(buffer + len, sizeof(buffer) - len, 2);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "a");
    len += cbor_begin_definite_map(buffer + len, sizeof(buffer) - len, 1);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "b");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "c");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}

void encode_test_048(void) {
    const uint8_t hex[] = {0xa5, 0x61, 0x61, 0x61, 0x41, 0x61, 0x62, 0x61, 0x42, 0x61, 0x63, 0x61, 0x43, 0x61, 0x64, 0x61, 0x44, 0x61, 0x65, 0x61, 0x45};
    const char *diag = "{\"a\": \"A\", \"b\": \"B\", \"c\": \"C\", \"d\": \"D\", \"e\": \"E\"}";
    uint8_t buffer[21];
    size_t len = 0;
    printf("\nEncode test 048\nInput: %s\n", diag);
    len += cbor_begin_definite_map(buffer + len, sizeof(buffer) - len, 5);
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "a");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "A");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "b");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "B");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "c");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "C");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "d");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "D");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "e");
    len += cbor_set_text_string(buffer + len, sizeof(buffer) - len, "E");
    printf("Expecting: ");
    print_buffer(hex, sizeof(hex));
    printf("\nEncoded  : ");
    print_buffer(buffer, sizeof(buffer));
    printf("\n");
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, hex, sizeof(hex));
}



void encode_tests(void) {
RUN_TEST(encode_test_000);
RUN_TEST(encode_test_001);
RUN_TEST(encode_test_002);
RUN_TEST(encode_test_003);
RUN_TEST(encode_test_004);
RUN_TEST(encode_test_005);
RUN_TEST(encode_test_006);
RUN_TEST(encode_test_007);
RUN_TEST(encode_test_008);
RUN_TEST(encode_test_009);
RUN_TEST(encode_test_010);
RUN_TEST(encode_test_011);
RUN_TEST(encode_test_012);
RUN_TEST(encode_test_013);
RUN_TEST(encode_test_014);
RUN_TEST(encode_test_015);
RUN_TEST(encode_test_016);
RUN_TEST(encode_test_017);
RUN_TEST(encode_test_018);
RUN_TEST(encode_test_019);
RUN_TEST(encode_test_020);
RUN_TEST(encode_test_021);
RUN_TEST(encode_test_022);
RUN_TEST(encode_test_023);
RUN_TEST(encode_test_024);
RUN_TEST(encode_test_025);
RUN_TEST(encode_test_026);
RUN_TEST(encode_test_027);
RUN_TEST(encode_test_028);
RUN_TEST(encode_test_029);
RUN_TEST(encode_test_030);
RUN_TEST(encode_test_031);
RUN_TEST(encode_test_032);
RUN_TEST(encode_test_033);
RUN_TEST(encode_test_034);
RUN_TEST(encode_test_035);
RUN_TEST(encode_test_036);
RUN_TEST(encode_test_037);
RUN_TEST(encode_test_038);
RUN_TEST(encode_test_039);
RUN_TEST(encode_test_040);
RUN_TEST(encode_test_041);
RUN_TEST(encode_test_042);
RUN_TEST(encode_test_043);
RUN_TEST(encode_test_044);
RUN_TEST(encode_test_045);
RUN_TEST(encode_test_046);
RUN_TEST(encode_test_047);
RUN_TEST(encode_test_048);
}
