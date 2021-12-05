#include "cboring_simple.h"
#include "cboring_internal.h"
#include <assert.h>

bool cbor_is_simple(const uint8_t *buffer, size_t len) {
    return len > 0 &&
        MAJOR_TYPE(buffer) == CBOR_FLOAT_AND_SIMPLE &&
        (ADDITIONAL_INFO(buffer) == CBOR_FALSE || ADDITIONAL_INFO(buffer) == CBOR_TRUE ||
         ADDITIONAL_INFO(buffer) == CBOR_NULL || ADDITIONAL_INFO(buffer) == CBOR_UNDEFINED);
}

bool cbor_is_bool(const uint8_t *buffer, size_t len) {
    return len > 0 &&
        MAJOR_TYPE(buffer) == CBOR_FLOAT_AND_SIMPLE &&
        (ADDITIONAL_INFO(buffer) == CBOR_FALSE || ADDITIONAL_INFO(buffer) == CBOR_TRUE);
}


bool cbor_get_bool(const uint8_t *buffer, size_t len) {
    return cbor_is_true(buffer, len);
}

bool cbor_is_true(const uint8_t *buffer, size_t len) {
    return len > 0 && ADDITIONAL_INFO(buffer) == CBOR_TRUE;
}

bool cbor_is_false(const uint8_t *buffer, size_t len) {
    return len > 0 && ADDITIONAL_INFO(buffer) == CBOR_FALSE;
}

bool cbor_is_null(const uint8_t *buffer, size_t len) {
    return len > 0 && ADDITIONAL_INFO(buffer) == CBOR_NULL;
}

bool cbor_is_undefined(const uint8_t *buffer, size_t len) {
    return len > 0 && ADDITIONAL_INFO(buffer) == CBOR_UNDEFINED;
}


static size_t cbor_set_simple(uint8_t *buffer, size_t maxlen, uint8_t simple_val) {
    if (maxlen > 0) {
        *buffer = CBOR_FLOAT_AND_SIMPLE << MAJOR_TYPE_OFFSET;
        *buffer |= simple_val & ADDITIONAL_INFO_MASK;
        return 1;
    }
    return 0;
}

size_t cbor_set_bool(uint8_t *buffer, size_t maxlen, bool val)
{
    return cbor_set_simple(buffer, maxlen, (val) ? CBOR_TRUE : CBOR_FALSE);
}

size_t cbor_set_true(uint8_t *buffer, size_t maxlen) {
    return cbor_set_simple(buffer, maxlen, CBOR_TRUE);
}

size_t cbor_set_false(uint8_t *buffer, size_t maxlen) {
    return cbor_set_simple(buffer, maxlen, CBOR_FALSE);
}

size_t cbor_set_null(uint8_t *buffer, size_t maxlen) {
    return cbor_set_simple(buffer, maxlen, CBOR_NULL);
}

size_t cbor_set_undefined(uint8_t *buffer, size_t maxlen) {
    return cbor_set_simple(buffer, maxlen, CBOR_UNDEFINED);
}
