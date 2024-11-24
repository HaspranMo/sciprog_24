#include <stdio.h>  
#include <math.h>   // Math library 
#define POINTS 12

float tan_values[POINTS + 1];
float degrees_to_radians(float degrees);
float compute_trape_area();

int main() {
    // Variables
    int index;
    float angle_deg;
    for (index = 0; index <= POINTS; index++) {
        angle_deg = index * 5.0;  //angle (0, 5, ..., 60)
        tan_values[index] = tan(degrees_to_radians(angle_deg));
        printf("tan_values[%d] = %.6f\n", index, tan_values[index]);
    }

    // using the Trapezoidal Rule
    float integral_result = compute_trape_area();

    // Display and compare with log(2)
    printf("Trapezoidal rule approximation: %f\n", integral_result);
    printf("Exact value (log(2)): %f\n", logf(2));

    return 0;
}

float degrees_to_radians(float degrees) {
    const float PI = 3.1415927;  // Approximation
    return (degrees * PI) / 180;
}

float compute_trape_area() {
    float total_area = tan_values[0] + tan_values[POINTS];
    printf("\nInitial area (from endpoints): %f\n", total_area);

    for (int i = 1; i < POINTS; i++) {
        total_area += 2 * tan_values[i];
    }

    //using the Trapezoidal Rule formula
    float scaling_factor = degrees_to_radians(60) / (2 * POINTS);
    total_area *= scaling_factor;

    printf("Total area(applying Trapezoidal Rule): %f\n", total_area);
    return total_area;
}

