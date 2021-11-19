#ifndef CBORING_ARRAY_H
#define CBORING_ARRAY_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cbor_is_array(const uint8_t *buffer, size_t len);

#endif
