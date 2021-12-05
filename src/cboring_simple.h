#ifndef CBORING_SIMPLE_H
#define CBORING_SIMPLE_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool cbor_is_simple(const uint8_t *buffer, size_t len);
bool cbor_is_bool(const uint8_t *buffer, size_t len);

bool cbor_get_bool(const uint8_t *buffer, size_t len);
bool cbor_is_true(const uint8_t *buffer, size_t len);
bool cbor_is_false(const uint8_t *buffer, size_t len);
bool cbor_is_null(const uint8_t *buffer, size_t len);
bool cbor_is_undefined(const uint8_t *buffer, size_t len);

size_t cbor_set_bool(uint8_t *buffer, size_t maxlen, bool val);
size_t cbor_set_true(uint8_t *buffer, size_t maxlen);
size_t cbor_set_false(uint8_t *buffer, size_t maxlen);
size_t cbor_set_null(uint8_t *buffer, size_t maxlen);
size_t cbor_set_undefined(uint8_t *buffer, size_t maxlen);


#endif
