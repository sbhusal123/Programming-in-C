#include <stdlib.h>
#include <stdio.h>

void using_malloc_calloc()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    // allocating 1D array of size n, Those m/m address are initialized to 0.
    int *a = (int *)calloc(n, sizeof(int));

    /* 
    // Uncomment to display initialized value. i.e 0
    printf("\nElements stored after calloc: \n");
    for (int i = 0; i < n; i++)
        printf("a[%d]=%d\n", i, a[i]);    // 0 -> init with calloc
    */

    // Filling in the array
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    /*
        Even if we free: free(a) still these memory address can be accessed.
        But the address content may have some garbade value. So it's a good idea to set a pointer to NULL

    */

    free(a);
    a = NULL; // caveats, always point to NULL after deallocation;

    a = (int *)malloc(n * sizeof(int)); // new block allocated, garbage value by default
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    /* 
    // Uncomment to display garbade value. 
    printf("\nElements stored after malloc initialization: \n");
    for (int i = 0; i < n; i++)
        printf("a[%d]=%d\n", i, a[i]);   // grabage value -> init with malloc
    */
    printf("\nElements stored: \n");
    for (int i = 0; i < n; i++)
        printf("a[%d]=%d\n", i, a[i]);

    printf("\n");
}

void using_realloc()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    // allocate and initialize n dim 1d array
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    // Display elements
    printf("\n\nBefore  Realloc  Content Array[%d] are: \n", n);
    for (int i = 0; i < n; i++)
        printf("a[%d]=%d\n", i, a[i]);

    // Display Address
    printf("\nBefore  Realloc  Address &Array[%d] are: \n", n);
    for (int i = 0; i < n; i++)
        printf("a[%d]=%d\n", i, &a[i]);

    // reallocate it : change size 2*n d array, Extra address allocated will have value initialized to 0.
    int *b = (int *)realloc(a, 2 * n * sizeof(int));

    // Display elements
    printf("\n\nAfter changing size  to %d, contents Array[%d] are: \n", 2 * n, 2 * n);
    for (int i = 0; i < 2 * n; i++)
        printf("a[%d]=%d\n", i, a[i]);

    printf("\nAfter Realloc  Address &Array[%d] are: \n", 2 * n);
    for (int i = 0; i < 2 * n; i++)
        printf("a[%d]=%d\n", i, &a[i]);

    free(a);

    /*
    Output:

        Enter the size of array: 2


        Before  Realloc  Content Array[2] are: 
        a[0]=1
        a[1]=2

        Before  Realloc  Address &Array[2] are: 
        a[0]=1433762432
        a[1]=1433762436


        After changing size  to 4, contents Array[4] are: 
        a[0]=1
        a[1]=2
        a[2]=0
        a[3]=0

        After Realloc  Address &Array[4] are: 
        a[0]=1433762432
        a[1]=1433762436
        a[2]=1433762440
        a[3]=1433762444
    */
}

int main(int *argc, char *argv[])
{
    // using_malloc_calloc();
    using_realloc();
    return 0;
}