#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include "cboring.h"
#include "cboring_string.h"

/* "Hello World!" */
uint8_t test_string[] = {0x6C, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21};

void test_decode(const uint8_t *buffer, size_t len, const char *expected) {
    printf("This is a string (%s) and should be \"%s\": %.*s\n",
           cboring_is_text_string(buffer, len) ? "yes" : "no",
           expected,
           (int)cboring_get_string_length(buffer, len),
           cboring_get_string_handle(buffer, len));
}

void print_buffer(const uint8_t *buffer, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%c0x%02X%c",
               (i == 0) ? '[' : ' ',
               buffer[i],
               (i < len - 1) ? ',' : ']');
    }
}

void test_encode(const char *val, const uint8_t *expected, size_t elen) {
    uint8_t buffer[256];
    size_t len = cboring_set_text_string(buffer, sizeof(buffer), val);
    /* Evaluate buffer */
    printf("Encoding result for %s: \n", val);
    printf(" Should be: ");
    print_buffer(expected, elen);
    printf("\n Result is: ");
    print_buffer(buffer, len);
    printf("\n %s\n", (elen == len && memcmp(buffer, expected, len) == 0) ? "Identical" : "Different");
}

int main()
{
    test_decode(test_string, sizeof(test_string), "Hello World!");
    test_encode("Hello World!", test_string, sizeof(test_string));
    return 0;
}
