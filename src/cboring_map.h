#ifndef CBORING_MAP_H
#define CBORING_MAP_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cbor_is_map(const uint8_t *buffer, size_t len);
size_t cbor_map_length(const uint8_t *buffer, size_t len);
size_t cbor_map_get(const uint8_t *buffer, size_t len, const char *key);
size_t cbor_map_index_key(const uint8_t *buffer, size_t len, size_t index);
size_t cbor_map_index_value(const uint8_t *buffer, size_t len, size_t index);
size_t cbor_begin_definite_map(uint8_t *buffer, size_t maxlen, size_t size);
size_t cbor_begin_indefinite_map(uint8_t *buffer, size_t maxlen);
size_t cbor_end_indefinite_map(uint8_t *buffer, size_t maxlen);

#endif
