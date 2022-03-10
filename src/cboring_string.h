#ifndef CBORING_STRING_H
#define CBORING_STRING_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cboring_is_text_string(const uint8_t *buffer, size_t len);
bool cboring_is_byte_string(const uint8_t *buffer, size_t len);
const uint8_t *cboring_get_string_handle(const uint8_t *buffer, size_t len);
size_t cboring_get_string_length(const uint8_t *buffer, size_t len);
size_t cboring_set_text_string(uint8_t *buffer, size_t maxlen, const char *str);
size_t cboring_set_byte_string(uint8_t *buffer, size_t maxlen, const uint8_t *str, size_t len);

#endif
