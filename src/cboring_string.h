#ifndef CBORING_STRING_H
#define CBORING_STRING_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cbor_is_string(const uint8_t *buffer, size_t len);
const uint8_t *cbor_get_string_handle(const uint8_t *buffer, size_t len);
size_t cbor_get_string_length(const uint8_t *buffer, size_t len);
size_t cbor_set_string(uint8_t *buffer, size_t maxlen, const char *str);

#endif
