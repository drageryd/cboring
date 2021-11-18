#ifndef CBORING_H
#define CBORING_H

#include <stddef.h>
#include <stdint.h>

#include "cboring_int.h"
#include "cboring_string.h"
#include "cboring_map.h"
#include "cboring_array.h"

size_t cbor_item_length(const uint8_t *buffer, size_t len);

size_t cbor_print_item(const uint8_t *buffer, size_t len, int indentation, const char *endline);

#endif
