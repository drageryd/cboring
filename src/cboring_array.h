#ifndef CBORING_ARRAY_H
#define CBORING_ARRAY_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cboring_is_array(const uint8_t *buffer, size_t len);
size_t cboring_array_length(const uint8_t *buffer, size_t len);
size_t cboring_array_index(const uint8_t *buffer, size_t len, size_t index);
size_t cboring_begin_definite_array(uint8_t *buffer, size_t maxlen, size_t size);
size_t cboring_begin_indefinite_array(uint8_t *buffer, size_t maxlen);
size_t cboring_end_indefinite_array(uint8_t *buffer, size_t maxlen);

#endif
