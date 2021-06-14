#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

#define BASE_16         16
#define BASE_10         10
#define BASE_8          8
#define BASE_2          2
#define INT_MAX         32767
#define INT_MIN         -32768

/**
 * @brief Integer-to-ASCII
 *
 * Convert data from a standard integer type into an ASCII string
 *
 * @param data Interger data
 * @param ptr Pointer to ASCII array
 * @param base Interger base
 *
 * @return length of ASCII string converted.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII-to-Integer
 *
 * Convert data back from an ASCII represented string into an integer type.
 *
 * @param ptr Pointer to ASCII array
 * @param digits Number of digits
 * @param base Interger base
 *
 * @return Interger converted.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */