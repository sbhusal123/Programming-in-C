#include <stdio.h>
#include <stdlib.h>

int *sum_returning_pointer(int *x, int *y)
{
    /*
        Issues with this implementation:
        We're returning the pointer to the local variable.

                    Program Stack Memory
        -------------------------------------------------
        |   sum_returning_pointer(int *x, int *y)       |
        |           int *x, int *y                      |
        |           int z                               |
        -------------------------------------------------
        |       main(int *argc, char *argv[])           |
        |           int *argc; char *argv[],            |
        |            int *p, a, b;                      |
        -------------------------------------------------

        After the execution of function sum_returning_pointer, gets deallocated.
        Thus the content at the address of variable z becomes a garbage value.

        Caveat: 
            If a function is returning a pointer to the local variable, then the call order
            of those functions matters.

        Sloution:
            Using a dynamic memory allocatio.

    */
    int z = (*x) + (*y);
    return &z;
}

int *sum_returning_pointer_dma(int *x, int *y)
{
    int *z = (int *)malloc(sizeof(int));
    *z = *x + *y;
    return z; // z is a pointer, return type of function is pointer
}

void main(int *argc, char *argv[])
{
    int a = 1, b = 2;
    int *p = sum_returning_pointer_dma(&a, &b);
    printf("Sum = %d\n", *p);

    // free the memory
    free(p);
    p = NULL;
}
