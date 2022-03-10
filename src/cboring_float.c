#include "cboring_float.h"
#include "cboring_internal.h"
#include <math.h>

union float_argument {
    float f;
    uint32_t u32;
};

union double_argument {
    double d;
    uint64_t u64;
};

bool cboring_is_half(const uint8_t *buffer, size_t len) {
    return len > 0 &&
        MAJOR_TYPE(buffer) == CBORING_FLOAT_AND_SIMPLE &&
        ADDITIONAL_INFO(buffer) == CBORING_FOLLOWING_2;
}

float cboring_get_half(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cboring_get_argument(buffer, len, &argument);
    /* Half precision conversion from Appendix D, float instead of double
     * https://www.rfc-editor.org/rfc/rfc8949.html#section-appendix.d */
    unsigned int exp = (argument >> 10) & 0x1f;
    unsigned int mant = argument & 0x3ff;
    float val;
    if (exp == 0) {
        val = ldexpf(mant, -24);
    } else if (exp != 31) {
        val = ldexpf(mant + 1024, exp - 25);
    } else {
        val = (mant == 0) ? INFINITY : NAN;
    }
    return (argument & 0x8000) ? -val : val;
}

bool cboring_is_float(const uint8_t *buffer, size_t len) {
    return len > 0 &&
        MAJOR_TYPE(buffer) == CBORING_FLOAT_AND_SIMPLE &&
        ADDITIONAL_INFO(buffer) == CBORING_FOLLOWING_4;
}

float cboring_get_float(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cboring_get_argument(buffer, len, &argument);
    union float_argument fa;
    fa.u32 = (uint32_t)argument;
    return fa.f;
}

size_t cboring_set_float(uint8_t *buffer, size_t maxlen, float val) {
    if (maxlen >= 5) {
        *buffer = CBORING_FLOAT_AND_SIMPLE << MAJOR_TYPE_OFFSET;
        *buffer |= CBORING_FOLLOWING_4 & ADDITIONAL_INFO_MASK;
        union float_argument fa;
        fa.f = val;
        uint64_t v = (uint32_t)fa.u32;
        return 1 + cboring_setn(buffer + 1, 4, v);
    }
    return 0;
}

bool cboring_is_double(const uint8_t *buffer, size_t len) {
    return len > 0 &&
        MAJOR_TYPE(buffer) == CBORING_FLOAT_AND_SIMPLE &&
        ADDITIONAL_INFO(buffer) == CBORING_FOLLOWING_8;
}

double cboring_get_double(const uint8_t *buffer, size_t len) {
    union double_argument da;
    cboring_get_argument(buffer, len, &da.u64);
    return da.d;
}

size_t cboring_set_double(uint8_t *buffer, size_t maxlen, double val) {
    if (maxlen >= 9) {
        *buffer = CBORING_FLOAT_AND_SIMPLE << MAJOR_TYPE_OFFSET;
        *buffer |= CBORING_FOLLOWING_8 & ADDITIONAL_INFO_MASK;
        union double_argument da;
        da.d = val;
        uint64_t v = da.u64;
        return 1 + cboring_setn(buffer + 1, 8, v);
    }
    return 0;
}
