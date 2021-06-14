/**
 * @file data.c
 * @brief Basic data manipulation
 *
 * This implementation file provides basic data operations
 *
 * @author Fabio Contreras
 * @date January 10 2021
 *
 */
#include "data.h"
#include "platform.h"
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

    int n = 0;
    int i = 0;
    uint32_t tmp;
    uint8_t digits = 0;

    // Add sign to char array
    bool isNeg = data<0;

    // Convert data to positive
    tmp = isNeg ? (-1 * data) : data;

    // Add data to output array
    while(tmp!=0)
    {
        ptr[i] = (char)(tmp % base) + '0';
        tmp=tmp/base;
        i++;
    }

    if (isNeg) ptr[i] = '-';
    else ptr[i] = '+';
    i++;
    digits = i;

    for (int b = i; b< SIZEOF(ptr); b++) {
       ptr[b] = ' ';
    }

    my_reverse( ptr, SIZEOF(ptr));

    // for (int a = 0; a< SIZEOF(ptr); a++) {
    //     PRINTF("%d : %d\n", a, ptr[a]);
    // }

    return digits;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

    int sign = 1, i = 0;
    int32_t number = 0;
     
    // if whitespaces then ignore.
    while (ptr[i] == ' ')
    {
        i++;
    }
     
    // sign of number
    if (ptr[i] == '-') sign = -1;
    else sign = 1;
    i++;
    // checking for valid input
    // while (ptr[i] >= '0' && ptr[i] <= '9')
    // {
    //     // handling overflow test case
    //     if (base > INT_MAX / 10
    //         || (base == INT_MAX / 10
    //         && ptr[i] - '0' > 7))
    //     {
    //         if (sign == 1)
    //             return INT_MAX;
    //         else
    //             return INT_MIN;
    //     }
    for (int a = i; a < SIZEOF(ptr); a++)
        number = number + (ptr[a] - '0') * pow_custom(base,(SIZEOF(ptr)-1-a));
    // }
    return number * sign;
}

int32_t pow_custom(uint32_t base, int pot) {

    int i = 1;
    int32_t result;
    if (pot < 0) pot = 0;
    result = pot > 0 ? base : 1;
    while( i < pot){
        result = result*base;
        i++;
    }
    return result;
}
