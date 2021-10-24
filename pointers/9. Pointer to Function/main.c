#include <stdio.h>
#include <stdlib.h>

int sum_of_two_numbers(int x, int y)
{
    return x + y;
}

void foo(int x, int y)
{
    // printf("\nI'm a foo.\n");
    printf("\nSum=%d\n", x + y);
}

void main(void)
{
    int (*sum_ptr)(int, int);

    sum_ptr = sum_of_two_numbers;
    int z = sum_ptr(1, 2);
    // or
    // sum_ptr = &sum_of_two_numbers;
    // int z = (*sum_ptr)(1, 2);
    printf("%d", z);

    void (*foo_ptr)(int, int);
    foo_ptr = &foo;
    (*foo_ptr)(1, 2);
}