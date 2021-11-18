#ifndef CBORING_MAP_H
#define CBORING_MAP_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cbor_is_map(const uint8_t *buffer, size_t len);
size_t cbor_map_length(const uint8_t *buffer, size_t len);

#endif
