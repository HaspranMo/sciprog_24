#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"

#define MAX_FILE_NAME 100

// Function prototype to count the number of lines in the file
int getlines(char filename[MAX_FILE_NAME]);

int main() {
    FILE *f;
    char filename[MAX_FILE_NAME];
    int n;

    printf("Enter the file name: ");
    scanf("%s", filename);

    n = getlines(filename);
    if (n <= 0) {
        printf("Error: Invalid file or matrix size.\n");
        return 1;
    }

    // Open the file
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Allocate memory for the matrix
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Read the matrix data from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &matrix[i][j]);
        }
    }
    // Close the file
    fclose(f);

    // Check if the matrix is a magic square
    if (isMagicSquare(matrix, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is NOT a magic square.\n");
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

// Function to count the number of lines in the file
int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1; // Error open
    }

    int ch_read, count = 0;
    while ((ch_read = fgetc(fp)) != EOF) {
        if (ch_read == '\n') {
            count++;
        }
    }

    fclose(fp);
    return count;
}

