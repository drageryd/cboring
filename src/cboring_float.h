#ifndef CBORING_FLOAT_H
#define CBORING_FLOAT_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cboring_is_half(const uint8_t *buffer, size_t len);
float cboring_get_half(const uint8_t *buffer, size_t len);

bool cboring_is_float(const uint8_t *buffer, size_t len);
float cboring_get_float(const uint8_t *buffer, size_t len);
size_t cboring_set_float(uint8_t *buffer, size_t maxlen, float val);

bool cboring_is_double(const uint8_t *buffer, size_t len);
double cboring_get_double(const uint8_t *buffer, size_t len);
size_t cboring_set_double(uint8_t *buffer, size_t maxlen, double val);

#endif
