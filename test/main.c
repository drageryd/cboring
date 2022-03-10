#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include "cboring.h"
#include "cboring_float.h"
#include "unity.h"
#include "tests.h"

void setUp(void) {
}

void tearDown(void) {
}

/* Recursively decode item and print item as diagnostic */
size_t decode(const uint8_t *hex, size_t hex_len, char *dest, size_t dest_len);
size_t decode(const uint8_t *hex, size_t hex_len, char *dest, size_t dest_len) {
    size_t len = 0;
    /* If nothing is decoded at least the string should be null terminated */
    if (dest_len > 0) {
        *dest = '\0';
    }
    /* Decode integer */
    if (cboring_is_int(hex, hex_len)) {
        size_t r = snprintf(dest, dest_len, "%ld", cboring_get_int(hex, hex_len));
        if (r == 0) {
            return 0;
        }
        len += r;
    }
    /* Decode string */
    else if (cboring_is_text_string(hex, hex_len)) {
        size_t r = snprintf(dest, dest_len, "\"%.*s\"",
                            (int)cboring_get_string_length(hex, hex_len),
                            cboring_get_string_handle(hex, hex_len));
        if (r == 0) {
            return 0;
        }
        len += r;
    }
    else if (cboring_is_byte_string(hex, hex_len)) {
        size_t r = snprintf(dest, dest_len, "h'");
        size_t l = cboring_get_string_length(hex, hex_len);
        const uint8_t *str = cboring_get_string_handle(hex, hex_len);
        for (size_t i = 0; i < l; i++) {
            size_t t = snprintf(dest + r, dest_len - r, "%02X", str[i]);
            if (t == 0) {
                return 0;
            }
            r += t;
        }
        r += snprintf(dest + r, dest_len - r, "'");
        if (r == 0) {
            return 0;
        }
        len += r;
    }
    /* Decode floats */
    else if (cboring_is_half(hex, hex_len)) {
        size_t r = snprintf(dest, dest_len, "%e", cboring_get_half(hex, hex_len));
        if (r == 0) {
            return 0;
        }
        len += r;
    }
    else if (cboring_is_float(hex, hex_len)) {
        size_t r = snprintf(dest, dest_len, "%e", cboring_get_float(hex, hex_len));
        if (r == 0) {
            return 0;
        }
        len += r;
    }
    else if (cboring_is_double(hex, hex_len)) {
        size_t r = snprintf(dest, dest_len, "%e", cboring_get_double(hex, hex_len));
        if (r == 0) {
            return 0;
        }
        len += r;
    }
    /* Decode booleans */
    else if (cboring_is_simple(hex, hex_len)) {
        const char *simples[] = {
            "true",
            "false",
            "null",
            "undefined"
        };
        const char *s;
        if (cboring_is_true(hex, hex_len)) {
            s = simples[0];
        } else if (cboring_is_false(hex, hex_len)) {
            s = simples[1];
        } else if (cboring_is_null(hex, hex_len)) {
            s = simples[2];
        } else {
            s = simples[3];
        }
        size_t r = snprintf(dest, dest_len, "%s", s);
        if (r == 0) {
            return 0;
        }
        len += r;
    }
    /* Maps recursive */
    else if (cboring_is_map(hex, hex_len)) {
        size_t r, o;
        size_t map_length = cboring_map_length(hex, hex_len);
        if (len >= dest_len) {
            return 0;
        }
        dest[len++] = '{';
        dest[len] = '\0';
        for (size_t i = 0; i < map_length; i++) {
            if (i != 0) {
                if (len + 1 >= dest_len) {
                    return 0;
                }
                dest[len++] = ',';
                dest[len++] = ' ';
                dest[len] = '\0';
            }

            o = cboring_map_index_key(hex, hex_len, i);
            r = decode(hex + o, hex_len - o, dest + len, dest_len - len);
            if (r == 0) {
                return 0;
            }
            len += r;

            if (len + 1 >= dest_len) {
                return 0;
            }
            dest[len++] = ':';
            dest[len++] = ' ';
            dest[len] = '\0';

            o = cboring_map_index_value(hex, hex_len, i);
            r = decode(hex + o, hex_len - o, dest + len, dest_len - len);
            if (r == 0) {
                return 0;
            }
            len += r;
        }
        if (len >= dest_len) {
            return 0;
        }
        dest[len++] = '}';
        dest[len] = '\0';
    }
    /* Arrays recursive */
    else if (cboring_is_array(hex, hex_len)) {
        size_t r, o;
        size_t array_length = cboring_array_length(hex, hex_len);
        if (len >= dest_len) {
            return 0;
        }
        dest[len++] = '[';
        dest[len] = '\0';
        for (size_t i = 0; i < array_length; i++) {
            if (i != 0) {
                if (len + 1 >= dest_len) {
                    return 0;
                }
                dest[len++] = ',';
                dest[len++] = ' ';
                dest[len] = '\0';
            }

            o = cboring_array_index(hex, hex_len, i);
            r = decode(hex + o, hex_len - o, dest + len, dest_len - len);
            if (r == 0) {
                return 0;
            }
            len += r;
        }
        if (len >= dest_len) {
            return 0;
        }
        dest[len++] = ']';
        dest[len] = '\0';
    }
    return len;
}

int main()
{
    UNITY_BEGIN();
    decode_tests();
    encode_tests();
    return UNITY_END();
}
