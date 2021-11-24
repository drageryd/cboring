#ifndef CBORING_INT_H
#define CBORING_INT_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cbor_is_int(const uint8_t *buffer, size_t len);
int64_t cbor_get_int(const uint8_t *buffer, size_t len);
size_t cbor_set_int(uint8_t *buffer, size_t maxlen, int64_t val);

#endif

