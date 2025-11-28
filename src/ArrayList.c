#include "ArrayList.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void ArrayList_init_imp(size_t stride, ArrayList* array, size_t incrementSize) {
    size_t totalSize = stride * incrementSize;

    void* arrayPointer = malloc(totalSize);
    if (arrayPointer == NULL) {
        exit(70);
    }

    array->array = arrayPointer;
    array->elementSize = stride;
    array->arrayLength = incrementSize;
    array->arrayResetSize = incrementSize;
    array->arrayPosition = 0;
}

int ArrayList_length(ArrayList* array) {
    if (array->arrayPosition > INT32_MAX) {
        return INT32_MAX;
    }

    return array->arrayPosition;
}

void* ArrayList_get(ArrayList* array, const int index) {
    return array->array+index*array->elementSize;
}

void ArrayList_put(ArrayList* array, void* elem) {
    if (array->arrayPosition+1 > array->arrayLength) {
        // Array is not long enough
        void* newArrayPointer = realloc(array->array, array->arrayLength+array->arrayResetSize*array->elementSize);
        if (newArrayPointer == NULL) {
            exit(70);
        }

        array->arrayLength += array->arrayResetSize;
        array->array = newArrayPointer;
    }

    // Actual copy into the array
    memcpy(array->array+(array->arrayPosition)*array->elementSize, elem, array->elementSize);
    array->arrayPosition++;
}

void ArrayList_remove(ArrayList* array, const int index) {
    // Underflow
    if (array->arrayLength == 0 || array->arrayPosition == 0)
        return;

    // If the element is not at the end than I have to swap all the elements after back of 1
    for (int i = index; i < array->arrayPosition-1; i++) { // From index to last element - 1
        memcpy(
            array->array+(i*array->elementSize),        // to:   Element
            array->array+((i+1)*array->elementSize),    // from: Element + 1
            array->elementSize
        );
    }

    array->arrayPosition--;

    if (array->arrayPosition-1 <= array->arrayLength) { // If possible reduce size
        // Will reduce the array size                           Array actual size            -          Reset actual Size
        void* newArrayPointer = realloc(array->array, (array->elementSize*array->arrayLength)-(array->arrayResetSize*array->elementSize));
        if (newArrayPointer == NULL) {
            exit(70);
        }

        array->arrayLength -= array->arrayResetSize;
        array->array = newArrayPointer;
    }
}


void ArrayList_free(const ArrayList* array) {
    free(array->array);
}
