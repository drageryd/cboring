#ifndef CBORING_INT_H
#define CBORING_INT_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cboring_is_int(const uint8_t *buffer, size_t len);
int64_t cboring_get_int(const uint8_t *buffer, size_t len);
size_t cboring_set_int(uint8_t *buffer, size_t maxlen, int64_t val);

#endif
