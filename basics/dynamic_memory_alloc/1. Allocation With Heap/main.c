#include <stdio.h>
#include <stdlib.h>

int main(int *argc, char *argv[])
{
    int a;  // goes into stack
    int *p; // m/m address to store content stored is stored in stack

    p = (int *)malloc(sizeof(int)); // malloc returns a void pointer which needs to be typecasted
    *p = 10;

    free(p);  // free memory -> first block is deallocated
    p = NULL; // pointer is set to null, so that it can't be dereferenced

    p = (int *)malloc(sizeof(int)); // one more memory reserved
    *p = 400;
    return 0;
}