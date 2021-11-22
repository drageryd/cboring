#ifndef CBORING_ARRAY_H
#define CBORING_ARRAY_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cbor_is_array(const uint8_t *buffer, size_t len);
size_t cbor_array_length(const uint8_t *buffer, size_t len);
size_t cbor_array_index(const uint8_t *buffer, size_t len, size_t index);

#endif
