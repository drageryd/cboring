#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include "cboring.h"

/* "Hello World!" */
uint8_t test_string[] = {0x6C, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21};

int main()
{
    printf("This is a string (%s) and should be \"Hello World!\": %.*s\n",
           cbor_is_string(test_string, sizeof(test_string)) ? "yes" : "no",
           (int)cbor_get_string_length(test_string, sizeof(test_string)),
           cbor_get_string_handle(test_string, sizeof(test_string)));    
    return 0;
}
