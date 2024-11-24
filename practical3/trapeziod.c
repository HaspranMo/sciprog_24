#include <stdio.h>
#include <math.h>   // For tan() and log()

int main(void) {
    int N = 12;
    // Integration in degrees
    float a_deg = 0.0;    // Start of the range in degrees
    float b_deg = 60.0;   // End
    float b_rad = (M_PI * b_deg) / 180;  // Conversion formula: degrees -> radians

    float sum = tan(a_deg * M_PI / 180) + tan(b_rad);

    printf("Initial sum (before loop): %f\n", sum);

    for (int i = 5; i < 60; i += 5) {
        float x_rad = i * M_PI / 180;  // Convert degrees to radians
        sum += 2 * tan(x_rad); 
    }

    printf("Sum after including interior points(after loop): %f\n", sum);

    float integral = (b_rad - a_deg) / (2 * N) * sum;
    printf("Computed integral value: %f\n", integral);

    // Compare with the exact integral value log(2)
    float exact_value = logf(2); 
    printf("Exact integral value (log(2)): %f\n", exact_value);

    float abs_diff = fabs(integral - exact_value);
    float rel_diff = fabs(1.0 - (integral / exact_value));

    // Print the absolute and relative differences
    printf("Absolute difference: %f\n", abs_diff);
    printf("Relative difference: %f\n", rel_diff);

    return 0;
}


