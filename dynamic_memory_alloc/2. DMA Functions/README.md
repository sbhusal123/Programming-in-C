# DMA Library Functions:

**1. malloc**

-   Signature: `void* malloc(size_t size)`
-   Example: `char *p = (char*)malloc(sizeof(char))`
-   Puts garbage value in the address by default.
-   To allocate address for 10 integers: `int *p_arr = (int*)malloc(10*sizeof(int))`.
-   `p_arr` Returns a memory address pointing to first block.

**2. calloc**

-   Signature: `void* calloc(size_t num, size_t size)`
-   Takes two args, first numbers of elements, second size of each elements.
-   To allocate address for 10 integers: `int *p_arr = (int*)calloc(10, sizeof(int))`.
-   `p_arr` Returns a memory address pointing to first block.
-   **Difference:** `Sets all byte position to zero, no garbage value`

**3. realloc**

-   Signature: `void* realloc (void* ptr, size_t size)`
-   First arg: pointer to m/m address, second arg the size.
-   To change the size of memory address already allocated.

-   **If size of new block > size of old block** -> Machine creates entirely new block and copy content of prev blocks.
-   **Existing block may also be extended if new size > old size**

**4. free**

-   Frees the memory address allocated.
-   Signature: `void(void* ptr)`

> All these functions returns a void pointer / generic pointer thus needs a typecasting.

## 2. Examaple With Realloc:

```c
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
```

**Output:**

```text
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
```
