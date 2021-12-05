/* 
 * This is an auto-generated file so edit with caution
 * It creates decode tests from the cbor test-vectors repo
 * url: https://github.com/cbor/test-vectors
 *
 * Note: cboring does not support integers with the highest bit set
 *       for example uint64_t 0xFFFFFFFFFFFFFFFF will result in -1
 *       which is not what is desired.
 *
 * Usage
 * Compile this file, include the header file and call test_decode
 */

#ifndef TESTS_H
#define TESTS_H

void decode_tests(void);
void encode_tests(void);

#endif
