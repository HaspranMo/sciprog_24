#include <stdio.h> 
#include <stdlib.h>

// Declare matmult function
void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]);

int main() {
    // Dimensions of matrices
    const int n = 5, p = 3, q = 4;

    // matrices A B C
    double A[n][p];
    double B[p][q];
    double C[n][q];

    // Fill matrices A and B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            A[i][j] = i + j; // A[i][j] = i + j
        }
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            B[i][j] = i - j; // B[i][j] = i - j
        }
    }

    // C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0.0;
        }
    }

    // Call matmult to compute C = A * B
    matmult(n, p, q, A, B, C);

    // Print matrices A, B, and C
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%6.2f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("%6.2f ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix C (Result):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            printf("%6.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

