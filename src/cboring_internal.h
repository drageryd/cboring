#ifndef CBORING_INTERNAL_H
#define CBORING_INTERNAL_H

#include <stddef.h>
#include <stdint.h>

size_t cbor_getn(const uint8_t *buffer, size_t n, uint64_t *data);
size_t cbor_get_argument(const uint8_t *buffer, size_t len, uint64_t *argument);

#endif

