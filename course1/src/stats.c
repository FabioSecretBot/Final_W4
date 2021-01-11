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

#include <stdio.h>
#include "stats.h"
#include "platform.h"

#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array_in_order(test, SIZE);
  print_statistics(test, SIZE);

}

void print_statistics(unsigned char array[], int length) {

  int i;

  #ifdef VERBOSE
  //Printing stadistics
  PRINTF("Median: %d\nMean: %d\nMaximum: %d\nMinimum: %d\n",
          find_median(array, length),
          find_mean(array, length),
          find_maximum(array, length),
          find_minimum(array, length));
  #endif
}

void print_array_in_order(unsigned char array[], int length) {

  int i;
  unsigned char array_in_order[length];
  sort_array(array, array_in_order, length);

  #ifdef VERBOSE
  //Printing every character
  for (i = 0; i< length; i++) {
    PRINTF("%d : %d\n", i, array_in_order[i]);
  }
  #endif
}

int find_median(unsigned char array[], int length) {

  int median;
  unsigned char array_in_order[length];
  sort_array(array, array_in_order, length);

  //Finding median (depends on the parity of the length)
  if (length % 2 == 0) {
    median = (array_in_order[length/2] + array_in_order[length/2 - 1]) / 2;
  } else {
    median = array_in_order[(length - 1)/2];
  }

  return median;
}

int find_mean(unsigned char array[], int length) {

  int mean;
  int i;
  int sum = 0;

  //Finding mean
  for (i = 0; i < length; i++) {
    sum += array[i];
  }

  mean = sum/length;

  return mean;
}

int find_maximum(unsigned char array[], int length) {

  int maximum = 0;
  int i;

  //Finding maximum
  for (i = 0; i < length; i++) {
    if (array[i] > maximum) {
      maximum = array[i];
    }
  }

  return maximum;
}

int find_minimum(unsigned char array[], int length) {

  int minimum = array[0];
  int i;

  //Finding minimum
  for (i = 0; i < length; i++) {
    if (array[i] < minimum) {
      minimum = array[i];
    }
  }

  return minimum;
}

void sort_array(unsigned char array[],unsigned char array_to_order[], int length) {

  int i, a, b, header;

  //Copy the initial array to the sort array
  for (b = 0; b < length; b++) {
    array_to_order[b] = array[b];
  }

  //Sorting array
  for (i = 0; i < length; i++) {

    for (a = i + 1; a < length; a++) {

      if ( array_to_order[i] < array_to_order[a]) {
        header = array_to_order[i];
        array_to_order[i] = array_to_order[a];
        array_to_order[a] = header;

      }
    }
  }
}