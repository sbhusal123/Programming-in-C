/*
 * To print the hex address:
 * printf("\nHex address of x: %p \n", (void *)&x);
*/

/*
 * If p is a integer pointer pointing at 2145 location.
 * Then p+1 points to address: 2149, which increases by the size of int (4).
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int x;
    int *p; // pointer to integer

    x = 5;
    p = &x; // p now points to the address of x

    printf("Address of x= %d \n", &x);
    printf("Value of x= %d \n", x);
    printf("Integer pointer p= %d \n", p);
    printf("Value at address of p = %d \n", *p);

    printf("\n\nAddress pointed by p+1= %d \n", p + 1); // note that the content increases by size of int(4)
    printf("Content at p+1 address: %d \n", *(p + 1));  // this is grabage value as it is not initialized

    printf("\n\nSize of integer is: %d bytes \n\n", sizeof(int));

    // printf("\nHex address of x: %p \n", (void *)&x);

    return 0;
}

/*
Output:

Address of x= -9588 
Value of x= 5
Integer pointer p= -9588 
Value at address of p = 5 


Address pointed by p+1= -9584
Content at p+1 address: -9588 


Size of integer is: 4 bytes
*/