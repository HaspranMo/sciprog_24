#include <stdio.h>
int main(void) {
    int integer_input;
    double double_input;
    int input_status;

    // ask user for an integer and a f number
    printf("Please enter an integer and a floating-point number :\n");
    input_status = scanf("%d %lf", &integer_input, &double_input);

    // Validate input
    if (input_status != 2) {
        printf("Error: Invalid input..\n");
    } else {
        printf("You entered: Integer = %d, Double = %lf\n", integer_input, double_input);
    }

    return 0;
}

