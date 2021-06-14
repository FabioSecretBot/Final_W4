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

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

    int n = 0;
    char buffer[50];
    int i = 0;

    bool isNeg = data<0;

    unsigned int n1 = isNeg ? -n : n;

    while(n1!=0)
    {
        buffer[i++] = n1%base+'0';
        n1=n1/base;
    }

    if(isNeg)
        buffer[i++] = '-';

    buffer[i] = '\0';

    for(int t = 0; t < i/2; t++)
    {
        buffer[t] ^= buffer[i-t-1];
        buffer[i-t-1] ^= buffer[t];
        buffer[t] ^= buffer[i-t-1];
    }

    if(n == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
    }   

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

    int sign = 1, base = 0, i = 0;
     
    // if whitespaces then ignore.
    while (ptr[i] == ' ')
    {
        i++;
    }
     
    // sign of number
    if (ptr[i] == '-' || ptr[i] == '+')
    {
        sign = 1 - 2 * (ptr[i++] == '-');
    }
   
    // checking for valid input
    while (ptr[i] >= '0' && ptr[i] <= '9')
    {
        // handling overflow test case
        if (base > INT_MAX / 10
            || (base == INT_MAX / 10
            && ptr[i] - '0' > 7))
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        base = 10 * base + (ptr[i++] - '0');
    }
    return base * sign;
}

