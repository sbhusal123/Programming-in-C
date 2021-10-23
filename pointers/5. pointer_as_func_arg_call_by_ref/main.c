#include <stdio.h>

int add_numbers(int *x, int *y)
{
    printf("--------------Address of x and y in function-----------\n");
    printf("Address Pointed by *x (x)=%d\n", x);
    printf("Address poinnted by *y (y)=%d\n", y);
    printf("-------------------------------------------------------\n");
    return *x + *y;
}

void increament(int *x)
{
    /*
        * Performs inplace increament.
        * Notice the return type is void i.e. no return type.
        * Directly operates at the memory level so no need to return any type.
    */

    printf("--------------Address of x in main--------------\n");
    printf("Address pointer by *x (x)=%d\n", x);
    printf("-----------------------------------------------\n\n");
    *x = *x + 1;
}

int main(int argc, char *argv[])
{
    /*
        int x, y, sum;
        printf("Enter first number(x): ");
        scanf("%d", &x);
        printf("Enter second number(y): ");
        scanf("%d", &y);

        printf("--------------Address of x and y in main--------------\n");
        printf("Address of x (&x)=%d\n", &x);
        printf("Address of x (&y)=%d\n", &y);
        printf("-------------------------------------------------------\n\n");

        sum = add_numbers(&x, &y);

        printf("Sum=%d\n", sum);
    */

    int x;
    printf("Enter first number(x): ");
    scanf("%d", &x);

    printf("--------------Address of x in main--------------\n");
    printf("Address of x (&x)=%d\n", &x);
    printf("-----------------------------------------------\n\n");

    increament(&x);

    printf("After increament=%d\n\n", x);

    return 0;
}