#include <stdio.h>

int square(int x)
{
    return x * x;
}

int add(int x, int y, int (*callback_sqr)(int))
{
    int z = x + y;
    return callback_sqr(z);
}

void main(void)
{

    int x = 1, y = 2;
    int z = add(x, y, &square);
    printf("Sum of square: %d\n\n", z);
}