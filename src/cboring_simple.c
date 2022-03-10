#include "cboring_simple.h"
#include "cboring_internal.h"
#include <assert.h>

bool cboring_is_simple(const uint8_t *buffer, size_t len) {
    return len > 0 &&
        MAJOR_TYPE(buffer) == CBORING_FLOAT_AND_SIMPLE &&
        (ADDITIONAL_INFO(buffer) == CBORING_FALSE || ADDITIONAL_INFO(buffer) == CBORING_TRUE ||
         ADDITIONAL_INFO(buffer) == CBORING_NULL || ADDITIONAL_INFO(buffer) == CBORING_UNDEFINED);
}

bool cboring_is_bool(const uint8_t *buffer, size_t len) {
    return len > 0 &&
        MAJOR_TYPE(buffer) == CBORING_FLOAT_AND_SIMPLE &&
        (ADDITIONAL_INFO(buffer) == CBORING_FALSE || ADDITIONAL_INFO(buffer) == CBORING_TRUE);
}


bool cboring_get_bool(const uint8_t *buffer, size_t len) {
    return cboring_is_true(buffer, len);
}

bool cboring_is_true(const uint8_t *buffer, size_t len) {
    return len > 0 && ADDITIONAL_INFO(buffer) == CBORING_TRUE;
}

bool cboring_is_false(const uint8_t *buffer, size_t len) {
    return len > 0 && ADDITIONAL_INFO(buffer) == CBORING_FALSE;
}

bool cboring_is_null(const uint8_t *buffer, size_t len) {
    return len > 0 && ADDITIONAL_INFO(buffer) == CBORING_NULL;
}

bool cboring_is_undefined(const uint8_t *buffer, size_t len) {
    return len > 0 && ADDITIONAL_INFO(buffer) == CBORING_UNDEFINED;
}


static size_t cboring_set_simple(uint8_t *buffer, size_t maxlen, uint8_t simple_val) {
    if (maxlen > 0) {
        *buffer = CBORING_FLOAT_AND_SIMPLE << MAJOR_TYPE_OFFSET;
        *buffer |= simple_val & ADDITIONAL_INFO_MASK;
        return 1;
    }
    return 0;
}

size_t cboring_set_bool(uint8_t *buffer, size_t maxlen, bool val)
{
    return cboring_set_simple(buffer, maxlen, (val) ? CBORING_TRUE : CBORING_FALSE);
}

size_t cboring_set_true(uint8_t *buffer, size_t maxlen) {
    return cboring_set_simple(buffer, maxlen, CBORING_TRUE);
}

size_t cboring_set_false(uint8_t *buffer, size_t maxlen) {
    return cboring_set_simple(buffer, maxlen, CBORING_FALSE);
}

size_t cboring_set_null(uint8_t *buffer, size_t maxlen) {
    return cboring_set_simple(buffer, maxlen, CBORING_NULL);
}

size_t cboring_set_undefined(uint8_t *buffer, size_t maxlen) {
    return cboring_set_simple(buffer, maxlen, CBORING_UNDEFINED);
}
