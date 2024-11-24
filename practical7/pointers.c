#include <stdio.h>
#include <stdlib.h>

// Function to allocate an array
int *allocatearray(int size) {
    return (int *)malloc(size * sizeof(int));
}

// Function to fill the array with ones
void fillwithones(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 1;
    }
}

// Function to print the array
void printarray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to free allocated memory
void freearray(int *array) {
    free(array);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = allocatearray(size);
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fillwithones(array, size);
    printf("Array filled with ones: ");
    printarray(array, size);

    freearray(array);
    return 0;
}

