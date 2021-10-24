#include <stdio.h>
#include <stdlib.h>

// Defining custom type
typedef int (*sq_ptr)(int);

int square(int x)
{
    return x * x;
}

sq_ptr perform_sum_and_return_callback(int *x, int *y, int *z)
{
    // here we store the sum in the location pointed by z, intermediate value
    *z = *x + *y;

    // return &square
    return square; // passing the address of square function
}

void main()
{
    // Initial and final value
    int x = 2, y = 5, result, sum;

    sq_ptr square_function_pointer = perform_sum_and_return_callback(&x, &y, &sum);

    // passing the sum result returned to var sum to the callback returned.
    result = square_function_pointer(sum);

    printf("Sum of square of (%d,%d)= %d\n\n", x, y, result);
}