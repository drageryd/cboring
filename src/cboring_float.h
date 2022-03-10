#ifndef CBORING_FLOAT_H
#define CBORING_FLOAT_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cbor_is_half(const uint8_t *buffer, size_t len);
float cbor_get_half(const uint8_t *buffer, size_t len);

bool cbor_is_float(const uint8_t *buffer, size_t len);
float cbor_get_float(const uint8_t *buffer, size_t len);
size_t cbor_set_float(uint8_t *buffer, size_t maxlen, float val);

bool cbor_is_double(const uint8_t *buffer, size_t len);
double cbor_get_double(const uint8_t *buffer, size_t len);
size_t cbor_set_double(uint8_t *buffer, size_t maxlen, double val);

#endif
