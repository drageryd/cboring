/* 
 * This is an auto-generated file so edit with caution
 * It creates decode tests from the cbor test-vectors repo
 * url: https://github.com/cbor/test-vectors
 *
 * Usage
 * Compile this file, include the header file and call test_decode
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "unity.h"

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

void decode_test_000(void) {
    const uint8_t hex[] = {0x00};
    const char *diag = "0";
    char dest[2];
    printf("\nDecode test 000\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_001(void) {
    const uint8_t hex[] = {0x01};
    const char *diag = "1";
    char dest[2];
    printf("\nDecode test 001\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_002(void) {
    const uint8_t hex[] = {0x0a};
    const char *diag = "10";
    char dest[3];
    printf("\nDecode test 002\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_003(void) {
    const uint8_t hex[] = {0x17};
    const char *diag = "23";
    char dest[3];
    printf("\nDecode test 003\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_004(void) {
    const uint8_t hex[] = {0x18, 0x18};
    const char *diag = "24";
    char dest[3];
    printf("\nDecode test 004\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_005(void) {
    const uint8_t hex[] = {0x18, 0x19};
    const char *diag = "25";
    char dest[3];
    printf("\nDecode test 005\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_006(void) {
    const uint8_t hex[] = {0x18, 0x64};
    const char *diag = "100";
    char dest[4];
    printf("\nDecode test 006\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_007(void) {
    const uint8_t hex[] = {0x19, 0x03, 0xe8};
    const char *diag = "1000";
    char dest[5];
    printf("\nDecode test 007\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_008(void) {
    const uint8_t hex[] = {0x1a, 0x00, 0x0f, 0x42, 0x40};
    const char *diag = "1000000";
    char dest[8];
    printf("\nDecode test 008\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_009(void) {
    const uint8_t hex[] = {0x1b, 0x00, 0x00, 0x00, 0xe8, 0xd4, 0xa5, 0x10, 0x00};
    const char *diag = "1000000000000";
    char dest[14];
    printf("\nDecode test 009\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_010(void) {
    const uint8_t hex[] = {0x1b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    const char *diag = "18446744073709551615";
    char dest[21];
    printf("\nDecode test 010\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_011(void) {
    const uint8_t hex[] = {0xc2, 0x49, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const char *diag = "18446744073709551616";
    char dest[21];
    printf("\nDecode test 011\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_012(void) {
    const uint8_t hex[] = {0x3b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    const char *diag = "-18446744073709551616";
    char dest[22];
    printf("\nDecode test 012\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_013(void) {
    const uint8_t hex[] = {0xc3, 0x49, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const char *diag = "-18446744073709551617";
    char dest[22];
    printf("\nDecode test 013\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_014(void) {
    const uint8_t hex[] = {0x20};
    const char *diag = "-1";
    char dest[3];
    printf("\nDecode test 014\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_015(void) {
    const uint8_t hex[] = {0x29};
    const char *diag = "-10";
    char dest[4];
    printf("\nDecode test 015\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_016(void) {
    const uint8_t hex[] = {0x38, 0x63};
    const char *diag = "-100";
    char dest[5];
    printf("\nDecode test 016\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_017(void) {
    const uint8_t hex[] = {0x39, 0x03, 0xe7};
    const char *diag = "-1000";
    char dest[6];
    printf("\nDecode test 017\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_018(void) {
    const uint8_t hex[] = {0xf9, 0x00, 0x00};
    const char *diag = "0.0";
    char dest[4];
    printf("\nDecode test 018\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_019(void) {
    const uint8_t hex[] = {0xf9, 0x80, 0x00};
    const char *diag = "-0.0";
    char dest[5];
    printf("\nDecode test 019\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_020(void) {
    const uint8_t hex[] = {0xf9, 0x3c, 0x00};
    const char *diag = "1.0";
    char dest[4];
    printf("\nDecode test 020\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_021(void) {
    const uint8_t hex[] = {0xfb, 0x3f, 0xf1, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9a};
    const char *diag = "1.1";
    char dest[4];
    printf("\nDecode test 021\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_022(void) {
    const uint8_t hex[] = {0xf9, 0x3e, 0x00};
    const char *diag = "1.5";
    char dest[4];
    printf("\nDecode test 022\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_023(void) {
    const uint8_t hex[] = {0xf9, 0x7b, 0xff};
    const char *diag = "65504.0";
    char dest[8];
    printf("\nDecode test 023\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_024(void) {
    const uint8_t hex[] = {0xfa, 0x47, 0xc3, 0x50, 0x00};
    const char *diag = "100000.0";
    char dest[9];
    printf("\nDecode test 024\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_025(void) {
    const uint8_t hex[] = {0xfa, 0x7f, 0x7f, 0xff, 0xff};
    const char *diag = "3.4028234663852886e+38";
    char dest[23];
    printf("\nDecode test 025\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_026(void) {
    const uint8_t hex[] = {0xfb, 0x7e, 0x37, 0xe4, 0x3c, 0x88, 0x00, 0x75, 0x9c};
    const char *diag = "1e+300";
    char dest[7];
    printf("\nDecode test 026\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_027(void) {
    const uint8_t hex[] = {0xf9, 0x00, 0x01};
    const char *diag = "5.960464477539063e-08";
    char dest[22];
    printf("\nDecode test 027\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_028(void) {
    const uint8_t hex[] = {0xf9, 0x04, 0x00};
    const char *diag = "6.103515625e-05";
    char dest[16];
    printf("\nDecode test 028\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_029(void) {
    const uint8_t hex[] = {0xf9, 0xc4, 0x00};
    const char *diag = "-4.0";
    char dest[5];
    printf("\nDecode test 029\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_030(void) {
    const uint8_t hex[] = {0xfb, 0xc0, 0x10, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66};
    const char *diag = "-4.1";
    char dest[5];
    printf("\nDecode test 030\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_031(void) {
    const uint8_t hex[] = {0xf9, 0x7c, 0x00};
    const char *diag = "Infinity";
    char dest[9];
    printf("\nDecode test 031\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_032(void) {
    const uint8_t hex[] = {0xf9, 0x7e, 0x00};
    const char *diag = "NaN";
    char dest[4];
    printf("\nDecode test 032\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_033(void) {
    const uint8_t hex[] = {0xf9, 0xfc, 0x00};
    const char *diag = "-Infinity";
    char dest[10];
    printf("\nDecode test 033\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_034(void) {
    const uint8_t hex[] = {0xfa, 0x7f, 0x80, 0x00, 0x00};
    const char *diag = "Infinity";
    char dest[9];
    printf("\nDecode test 034\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_035(void) {
    const uint8_t hex[] = {0xfa, 0x7f, 0xc0, 0x00, 0x00};
    const char *diag = "NaN";
    char dest[4];
    printf("\nDecode test 035\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_036(void) {
    const uint8_t hex[] = {0xfa, 0xff, 0x80, 0x00, 0x00};
    const char *diag = "-Infinity";
    char dest[10];
    printf("\nDecode test 036\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_037(void) {
    const uint8_t hex[] = {0xfb, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const char *diag = "Infinity";
    char dest[9];
    printf("\nDecode test 037\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_038(void) {
    const uint8_t hex[] = {0xfb, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const char *diag = "NaN";
    char dest[4];
    printf("\nDecode test 038\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_039(void) {
    const uint8_t hex[] = {0xfb, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    const char *diag = "-Infinity";
    char dest[10];
    printf("\nDecode test 039\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_040(void) {
    const uint8_t hex[] = {0xf4};
    const char *diag = "false";
    char dest[6];
    printf("\nDecode test 040\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_041(void) {
    const uint8_t hex[] = {0xf5};
    const char *diag = "true";
    char dest[5];
    printf("\nDecode test 041\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_042(void) {
    const uint8_t hex[] = {0xf6};
    const char *diag = "null";
    char dest[5];
    printf("\nDecode test 042\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_043(void) {
    const uint8_t hex[] = {0xf7};
    const char *diag = "undefined";
    char dest[10];
    printf("\nDecode test 043\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_044(void) {
    const uint8_t hex[] = {0xf0};
    const char *diag = "simple(16)";
    char dest[11];
    printf("\nDecode test 044\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_045(void) {
    const uint8_t hex[] = {0xf8, 0x18};
    const char *diag = "simple(24)";
    char dest[11];
    printf("\nDecode test 045\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_046(void) {
    const uint8_t hex[] = {0xf8, 0xff};
    const char *diag = "simple(255)";
    char dest[12];
    printf("\nDecode test 046\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_047(void) {
    const uint8_t hex[] = {0xc0, 0x74, 0x32, 0x30, 0x31, 0x33, 0x2d, 0x30, 0x33, 0x2d, 0x32, 0x31, 0x54, 0x32, 0x30, 0x3a, 0x30, 0x34, 0x3a, 0x30, 0x30, 0x5a};
    const char *diag = "0(\"2013-03-21T20:04:00Z\")";
    char dest[26];
    printf("\nDecode test 047\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_048(void) {
    const uint8_t hex[] = {0xc1, 0x1a, 0x51, 0x4b, 0x67, 0xb0};
    const char *diag = "1(1363896240)";
    char dest[14];
    printf("\nDecode test 048\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_049(void) {
    const uint8_t hex[] = {0xc1, 0xfb, 0x41, 0xd4, 0x52, 0xd9, 0xec, 0x20, 0x00, 0x00};
    const char *diag = "1(1363896240.5)";
    char dest[16];
    printf("\nDecode test 049\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_050(void) {
    const uint8_t hex[] = {0xd7, 0x44, 0x01, 0x02, 0x03, 0x04};
    const char *diag = "23(h'01020304')";
    char dest[16];
    printf("\nDecode test 050\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_051(void) {
    const uint8_t hex[] = {0xd8, 0x18, 0x45, 0x64, 0x49, 0x45, 0x54, 0x46};
    const char *diag = "24(h'6449455446')";
    char dest[18];
    printf("\nDecode test 051\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_052(void) {
    const uint8_t hex[] = {0xd8, 0x20, 0x76, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x65, 0x78, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d};
    const char *diag = "32(\"http://www.example.com\")";
    char dest[29];
    printf("\nDecode test 052\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_053(void) {
    const uint8_t hex[] = {0x40};
    const char *diag = "h''";
    char dest[4];
    printf("\nDecode test 053\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_054(void) {
    const uint8_t hex[] = {0x44, 0x01, 0x02, 0x03, 0x04};
    const char *diag = "h'01020304'";
    char dest[12];
    printf("\nDecode test 054\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_055(void) {
    const uint8_t hex[] = {0x60};
    const char *diag = "\"\"";
    char dest[3];
    printf("\nDecode test 055\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_056(void) {
    const uint8_t hex[] = {0x61, 0x61};
    const char *diag = "\"a\"";
    char dest[4];
    printf("\nDecode test 056\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_057(void) {
    const uint8_t hex[] = {0x64, 0x49, 0x45, 0x54, 0x46};
    const char *diag = "\"IETF\"";
    char dest[7];
    printf("\nDecode test 057\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_058(void) {
    const uint8_t hex[] = {0x62, 0x22, 0x5c};
    const char *diag = "\"\\\"\\\\\"";
    char dest[7];
    printf("\nDecode test 058\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_059(void) {
    const uint8_t hex[] = {0x62, 0xc3, 0xbc};
    const char *diag = "\"\\u00fc\"";
    char dest[9];
    printf("\nDecode test 059\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_060(void) {
    const uint8_t hex[] = {0x63, 0xe6, 0xb0, 0xb4};
    const char *diag = "\"\\u6c34\"";
    char dest[9];
    printf("\nDecode test 060\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_061(void) {
    const uint8_t hex[] = {0x64, 0xf0, 0x90, 0x85, 0x91};
    const char *diag = "\"\\ud800\\udd51\"";
    char dest[15];
    printf("\nDecode test 061\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_062(void) {
    const uint8_t hex[] = {0x80};
    const char *diag = "[]";
    char dest[3];
    printf("\nDecode test 062\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_063(void) {
    const uint8_t hex[] = {0x83, 0x01, 0x02, 0x03};
    const char *diag = "[1, 2, 3]";
    char dest[10];
    printf("\nDecode test 063\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_064(void) {
    const uint8_t hex[] = {0x83, 0x01, 0x82, 0x02, 0x03, 0x82, 0x04, 0x05};
    const char *diag = "[1, [2, 3], [4, 5]]";
    char dest[20];
    printf("\nDecode test 064\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_065(void) {
    const uint8_t hex[] = {0x98, 0x19, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x18, 0x18, 0x19};
    const char *diag = "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]";
    char dest[92];
    printf("\nDecode test 065\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_066(void) {
    const uint8_t hex[] = {0xa0};
    const char *diag = "{}";
    char dest[3];
    printf("\nDecode test 066\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_067(void) {
    const uint8_t hex[] = {0xa2, 0x01, 0x02, 0x03, 0x04};
    const char *diag = "{1: 2, 3: 4}";
    char dest[13];
    printf("\nDecode test 067\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_068(void) {
    const uint8_t hex[] = {0xa2, 0x61, 0x61, 0x01, 0x61, 0x62, 0x82, 0x02, 0x03};
    const char *diag = "{\"a\": 1, \"b\": [2, 3]}";
    char dest[22];
    printf("\nDecode test 068\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_069(void) {
    const uint8_t hex[] = {0x82, 0x61, 0x61, 0xa1, 0x61, 0x62, 0x61, 0x63};
    const char *diag = "[\"a\", {\"b\": \"c\"}]";
    char dest[18];
    printf("\nDecode test 069\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_070(void) {
    const uint8_t hex[] = {0xa5, 0x61, 0x61, 0x61, 0x41, 0x61, 0x62, 0x61, 0x42, 0x61, 0x63, 0x61, 0x43, 0x61, 0x64, 0x61, 0x44, 0x61, 0x65, 0x61, 0x45};
    const char *diag = "{\"a\": \"A\", \"b\": \"B\", \"c\": \"C\", \"d\": \"D\", \"e\": \"E\"}";
    char dest[51];
    printf("\nDecode test 070\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_071(void) {
    const uint8_t hex[] = {0x5f, 0x42, 0x01, 0x02, 0x43, 0x03, 0x04, 0x05, 0xff};
    const char *diag = "(_ h'0102', h'030405')";
    char dest[23];
    printf("\nDecode test 071\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_072(void) {
    const uint8_t hex[] = {0x7f, 0x65, 0x73, 0x74, 0x72, 0x65, 0x61, 0x64, 0x6d, 0x69, 0x6e, 0x67, 0xff};
    const char *diag = "\"streaming\"";
    char dest[12];
    printf("\nDecode test 072\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_073(void) {
    const uint8_t hex[] = {0x9f, 0xff};
    const char *diag = "[]";
    char dest[3];
    printf("\nDecode test 073\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_074(void) {
    const uint8_t hex[] = {0x9f, 0x01, 0x82, 0x02, 0x03, 0x9f, 0x04, 0x05, 0xff, 0xff};
    const char *diag = "[1, [2, 3], [4, 5]]";
    char dest[20];
    printf("\nDecode test 074\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_075(void) {
    const uint8_t hex[] = {0x9f, 0x01, 0x82, 0x02, 0x03, 0x82, 0x04, 0x05, 0xff};
    const char *diag = "[1, [2, 3], [4, 5]]";
    char dest[20];
    printf("\nDecode test 075\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_076(void) {
    const uint8_t hex[] = {0x83, 0x01, 0x82, 0x02, 0x03, 0x9f, 0x04, 0x05, 0xff};
    const char *diag = "[1, [2, 3], [4, 5]]";
    char dest[20];
    printf("\nDecode test 076\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_077(void) {
    const uint8_t hex[] = {0x83, 0x01, 0x9f, 0x02, 0x03, 0xff, 0x82, 0x04, 0x05};
    const char *diag = "[1, [2, 3], [4, 5]]";
    char dest[20];
    printf("\nDecode test 077\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_078(void) {
    const uint8_t hex[] = {0x9f, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x18, 0x18, 0x19, 0xff};
    const char *diag = "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]";
    char dest[92];
    printf("\nDecode test 078\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_079(void) {
    const uint8_t hex[] = {0xbf, 0x61, 0x61, 0x01, 0x61, 0x62, 0x9f, 0x02, 0x03, 0xff, 0xff};
    const char *diag = "{\"a\": 1, \"b\": [2, 3]}";
    char dest[22];
    printf("\nDecode test 079\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_080(void) {
    const uint8_t hex[] = {0x82, 0x61, 0x61, 0xbf, 0x61, 0x62, 0x61, 0x63, 0xff};
    const char *diag = "[\"a\", {\"b\": \"c\"}]";
    char dest[18];
    printf("\nDecode test 080\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}

void decode_test_081(void) {
    const uint8_t hex[] = {0xbf, 0x63, 0x46, 0x75, 0x6e, 0xf5, 0x63, 0x41, 0x6d, 0x74, 0x21, 0xff};
    const char *diag = "{\"Fun\": true, \"Amt\": -2}";
    char dest[25];
    printf("\nDecode test 081\nBuffer: ");
    print_buffer(hex, sizeof(hex));
    printf("\nExpecting: %s (%zu)\n", diag, strlen(diag));
    size_t l = decode(hex, sizeof(hex), dest, sizeof(dest));
    printf("Result   : %s (%zu)\n", dest, strlen(dest));
    TEST_ASSERT(l != 0);
    TEST_ASSERT(l == strlen(diag));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(diag, dest, sizeof(dest));
}



void decode_tests(void) {
RUN_TEST(decode_test_000);
RUN_TEST(decode_test_001);
RUN_TEST(decode_test_002);
RUN_TEST(decode_test_003);
RUN_TEST(decode_test_004);
RUN_TEST(decode_test_005);
RUN_TEST(decode_test_006);
RUN_TEST(decode_test_007);
RUN_TEST(decode_test_008);
RUN_TEST(decode_test_009);
RUN_TEST(decode_test_010);
RUN_TEST(decode_test_011);
RUN_TEST(decode_test_012);
RUN_TEST(decode_test_013);
RUN_TEST(decode_test_014);
RUN_TEST(decode_test_015);
RUN_TEST(decode_test_016);
RUN_TEST(decode_test_017);
RUN_TEST(decode_test_018);
RUN_TEST(decode_test_019);
RUN_TEST(decode_test_020);
RUN_TEST(decode_test_021);
RUN_TEST(decode_test_022);
RUN_TEST(decode_test_023);
RUN_TEST(decode_test_024);
RUN_TEST(decode_test_025);
RUN_TEST(decode_test_026);
RUN_TEST(decode_test_027);
RUN_TEST(decode_test_028);
RUN_TEST(decode_test_029);
RUN_TEST(decode_test_030);
RUN_TEST(decode_test_031);
RUN_TEST(decode_test_032);
RUN_TEST(decode_test_033);
RUN_TEST(decode_test_034);
RUN_TEST(decode_test_035);
RUN_TEST(decode_test_036);
RUN_TEST(decode_test_037);
RUN_TEST(decode_test_038);
RUN_TEST(decode_test_039);
RUN_TEST(decode_test_040);
RUN_TEST(decode_test_041);
RUN_TEST(decode_test_042);
RUN_TEST(decode_test_043);
RUN_TEST(decode_test_044);
RUN_TEST(decode_test_045);
RUN_TEST(decode_test_046);
RUN_TEST(decode_test_047);
RUN_TEST(decode_test_048);
RUN_TEST(decode_test_049);
RUN_TEST(decode_test_050);
RUN_TEST(decode_test_051);
RUN_TEST(decode_test_052);
RUN_TEST(decode_test_053);
RUN_TEST(decode_test_054);
RUN_TEST(decode_test_055);
RUN_TEST(decode_test_056);
RUN_TEST(decode_test_057);
RUN_TEST(decode_test_058);
RUN_TEST(decode_test_059);
RUN_TEST(decode_test_060);
RUN_TEST(decode_test_061);
RUN_TEST(decode_test_062);
RUN_TEST(decode_test_063);
RUN_TEST(decode_test_064);
RUN_TEST(decode_test_065);
RUN_TEST(decode_test_066);
RUN_TEST(decode_test_067);
RUN_TEST(decode_test_068);
RUN_TEST(decode_test_069);
RUN_TEST(decode_test_070);
RUN_TEST(decode_test_071);
RUN_TEST(decode_test_072);
RUN_TEST(decode_test_073);
RUN_TEST(decode_test_074);
RUN_TEST(decode_test_075);
RUN_TEST(decode_test_076);
RUN_TEST(decode_test_077);
RUN_TEST(decode_test_078);
RUN_TEST(decode_test_079);
RUN_TEST(decode_test_080);
RUN_TEST(decode_test_081);
}
