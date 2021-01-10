/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief My firts homework
 *
 * Hello, this is my firts coursera homework
 *
 * @author Fabio Contreras Coronado
 * @date 23/09/2020
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param array The array for the estatistics
 * @param length The length of the array
 *
 */
void print_statistics(unsigned char array[], int length);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param array The array to be printed
 * @param length The length of the array
 *
 */
void print_array_in_order(unsigned char array[], int length);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param array The array for the median
 * @param length The length of the array
 *
 * @return madian of the array elements
 */
int find_median(unsigned char array[], int length);

/**
 * @brief Given an array of data and a length, returns the mean
 *
 * @param array The array for the mean
 * @param length The length of the array
 *
 * @return mean of the array elements
 */
int find_mean(unsigned char array[], int length);

/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param array The array for the maximum
 * @param length The length of the array
 *
 * @return maximum element of the array
 */
int find_maximum(unsigned char array[], int length);

/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param array The array for the minimum
 * @param length The length of the array
 *
 * @return minimum element of the array
 */
int find_minimum(unsigned char array[], int length);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest. 
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @param array The array to be sorted
 * @param length The length of the array
 *
 * @return array in order
 * 
 */
void sort_array(unsigned char array[],unsigned char array_to_order[], int length);

#endif /* __STATS_H__ */
