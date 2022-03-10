#include "cboring_string.h"
#include "cboring_internal.h"
#include <string.h>

/* The support for indefinite strings is limited so for now
 * the _is_ functions return false if indefinite */
bool cboring_is_text_string(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cboring_get_argument(buffer, len, &argument);
    return MAJOR_TYPE(buffer) == CBORING_TEXT_STRING &&
        ADDITIONAL_INFO(buffer) != CBORING_INDEFINITE;
}

bool cboring_is_byte_string(const uint8_t *buffer, size_t len) {
    uint64_t argument;
    cboring_get_argument(buffer, len, &argument);
    return MAJOR_TYPE(buffer) == CBORING_BYTE_STRING &&
        ADDITIONAL_INFO(buffer) != CBORING_INDEFINITE;
}

/* Get any string type */
const uint8_t *cboring_get_string_handle(const uint8_t *buffer, size_t len) {
    /* Fetch argument */
    uint64_t argument;
    /* String payload starts after head */
    size_t string_start = cboring_get_argument(buffer, len, &argument);
    /* Major type in upper 3 bits of initial byte */
    switch (*buffer >> 5) {
    case 2:
        /* Byte string */
    case 3:
        /* Text string */
        return buffer + string_start;
    default:
        return 0;
    }
}

size_t cboring_get_string_length(const uint8_t *buffer, size_t len) {
    /* Fetch argument */
    uint64_t argument;
    /* String length is loaded into argument */
    cboring_get_argument(buffer, len, &argument);
    /* Major type in upper 3 bits of initial byte */
    switch (*buffer >> 5) {
    case 2:
        /* Byte string */
    case 3:
        /* Text string */
        return argument;
    default:
        return 0;
    }
}

/* Encode a null terminated string */
size_t cboring_set_text_string(uint8_t *buffer, size_t maxlen, const char *str)
{
    /* Store the length as argument
     * maxlen is subtracted to account for length of string */
    const size_t sl = strlen(str);
    size_t al = cboring_set_argument(buffer, maxlen - sl, CBORING_TEXT_STRING, sl);

    /* If buffer cant hold string, abort */
    if (al == 0) {
        return 0;
    }

    /* Store string in following bytes */
    memcpy(buffer + al, str, sl);
    return al + sl;
}

/* Encode a byte string with length */
size_t cboring_set_byte_string(uint8_t *buffer, size_t maxlen, const uint8_t *str, size_t len)
{
    /* Store the length as argument
     * maxlen is subtracted to account for length of string */
    size_t al = cboring_set_argument(buffer, maxlen - len, CBORING_BYTE_STRING, len);

    /* If buffer cant hold string, abort */
    if (al == 0) {
        return 0;
    }

    /* Store string in following bytes */
    memcpy(buffer + al, str, len);
    return al + len;
}
