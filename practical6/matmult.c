#include <stdio.h>

// Function: multiply matrices A and B, store result in C
void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
