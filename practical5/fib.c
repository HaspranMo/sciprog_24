#include <stdio.h>  
#include <stdlib.h> 

// Function to calculate the next Fibonacci number
void next_fib(int *current, int *previous);

int main(void) {
    int n, fib_0 = 0, fib_1 = 1;

    // input
    printf("Enter the number of Fibonacci terms to display:\n");
    scanf("%d", &n);

    // Validate user input
    if (n < 1) {
        printf("Error: Input must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    // Display the Fibonacci sequence
    printf("Fibonacci sequence:\n");
    printf("%d, %d", fib_0, fib_1); // first two terms

    for (int i = 2; i < n; i++) { // Start loop from the third term
        next_fib(&fib_1, &fib_0); 
        printf(", %d", fib_1);
    }
    printf("\n");

    return 0;
}

void next_fib(int *current, int *previous) {
    int next = *current + *previous; 
    *previous = *current;           // Update the previous number
    *current = next;                // Update the current number
}

