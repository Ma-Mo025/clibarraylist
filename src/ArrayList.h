/**
 * Copyright © 2025 Ma-Mo025 MIT License (MIT)
 * 
 * # ArrayList
 * Is a structure that work similarly to a array but you can add infinite elements to it (as long as you have ram)
 */
#ifndef LIB_ARRAYLIST
#define LIB_ARRAYLIST
#include <stddef.h>

typedef struct {
  size_t elementSize;     // Size of a single element
  size_t arrayLength;     // Length of the array
  size_t arrayPosition;   // Position of the last element in the array 
  size_t arrayResetSize;  // Of how mutch increse/decrese the array length (this concides with the initial length)
  void*  array;           // Pointer to the array
} ArrayList;

/**
 * The function to initialize a ArrayList
 * @input type The type of array (int, char, etc...)
 * @input array The reference to the ArrayList structure to initialize
 * @input incrementSize The dimention to add/remove from the ArrayList (default to 1)
 */
#define ArrayList_init(type, array, ...) ArrayList_init_imp(sizeof(type), array, (1, ##__VA_ARGS__))
void ArrayList_init_imp(size_t stride, ArrayList* array, size_t incrementSize);

/**
 * @param array The ArrayList
 * @return The length of the ArrayList
 */
int ArrayList_length(ArrayList* array);

/**
 * @param array The array
 * @param index The index of the element you want
 * @return The element at the index
 */
void* ArrayList_get(ArrayList* array, int index);

/**
 * @param array The array
 * @param elem The element you want to insert
 */
void ArrayList_put(ArrayList* array, void* elem);

/**
 * @param array The array
 * @param index The index of the element
 */
void ArrayList_remove(ArrayList* array, int index);

/**
 * Function to free and eliminate the vector
 * @param array The array to free
 */
void ArrayList_free(const ArrayList* array);

#endif // !LIB_ARRAYLIST
