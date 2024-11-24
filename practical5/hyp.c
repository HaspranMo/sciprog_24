//second question
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

double arctanh1(double x, double precision);
double arctanh2(double x);

int main(void) {
    // Variable declarations
    double precision, x = -0.9;
    int max_iterations = 1000;
    double results_maclaurin[max_iterations];
    double results_logarithmic[max_iterations];
    int index = 0;

    // Prompt user for precision
    printf("Enter a positive precision value (delta):\n");
    scanf("%lf", &precision);

    // Validate precision
    if (precision <= 0) {
        printf("Error: Precision must be positive.\n");
        exit(EXIT_FAILURE);
    }

    // Loop from -0.9 to 0.9 (step size 0.1)
    while (x <= 0.9 && index < max_iterations) {
        results_maclaurin[index] = arctanh1(x, precision);
        results_logarithmic[index] = arctanh2(x);

        // Print differences between the two methods
        printf("x = %.2lf, Difference = %.10lf\n", x,
               fabs(results_maclaurin[index] - results_logarithmic[index]));

        x += 0.1; // Increment x by 0.1
        index++;
    }

    return 0;
}

//using Maclaurin series
double arctanh1(double x, double precision) {
    double term, result = 0.0;
    int n = 0;

    do {
        term = pow(x, 2 * n + 1) / (2 * n + 1); // Compute the nth term
        result += term;
        n++;
    } while (fabs(term) >= precision);

    return result;
}

//using logarithmic approximation
double arctanh2(double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}

