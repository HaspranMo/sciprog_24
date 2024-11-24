#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//
int isMagicSquare(int **square, const int n) {
    if (n <= 0 || square == NULL) {
        return 0;
    }

    // Calculate the magic constant M
    int M = n * (n * n + 1) / 2;

    // Check rows and columns
    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];  // Sum of the row
            colSum += square[j][i];  // ~ column
        }
        if (rowSum != M || colSum != M) {
            return 0;
        }
    }

    // Check main and secondary diagonals
    int mainDiagonalSum = 0, secondaryDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagonalSum += square[i][i];             // Top-left to bottom-right
        secondaryDiagonalSum += square[i][n - 1 - i]; // Top-right to bottom-left
    }

    if (mainDiagonalSum != M || secondaryDiagonalSum != M) {
        return 0;
    }

    // All checks passed, is a magic square
    return 1;
}

