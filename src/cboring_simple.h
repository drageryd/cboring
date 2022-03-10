#ifndef CBORING_SIMPLE_H
#define CBORING_SIMPLE_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cboring_is_simple(const uint8_t *buffer, size_t len);
bool cboring_is_bool(const uint8_t *buffer, size_t len);

bool cboring_get_bool(const uint8_t *buffer, size_t len);
bool cboring_is_true(const uint8_t *buffer, size_t len);
bool cboring_is_false(const uint8_t *buffer, size_t len);
bool cboring_is_null(const uint8_t *buffer, size_t len);
bool cboring_is_undefined(const uint8_t *buffer, size_t len);

size_t cboring_set_bool(uint8_t *buffer, size_t maxlen, bool val);
size_t cboring_set_true(uint8_t *buffer, size_t maxlen);
size_t cboring_set_false(uint8_t *buffer, size_t maxlen);
size_t cboring_set_null(uint8_t *buffer, size_t maxlen);
size_t cboring_set_undefined(uint8_t *buffer, size_t maxlen);


#endif
