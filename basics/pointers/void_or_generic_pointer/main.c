/*
  * Also known as generic pointer.
  * Void pointer cannot be increamented or decreamented.
  * Cannnot be dereferenced.
  * In the lower version of gcc, pointer arithmetic with void pointer was not allowed.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 5;
    int *p;
    p = &x;

    void *p0;
    p0 = p;

    printf("%d \n", p0);
    printf("%d \n", p0 + 1);

    // printf("%d \n", *p0); // error in dereferencing the void pointer

    return 0;
}