# Returning Pointer From Function

-   **Signature:** `<type>* func(args)`
-   **Example:** `int * sum(int &a, int *b)`

## 1. Example(Caveat):

> If a called function is returning the pointer pointing to the address of local variable allocated in stack.
> This return a garbage value, cause once the function finishes execution, it's gets cleared from stack.

**Example:**

```c
int *sum_returning_pointer(int *x, int *y)
{
    int z = (*x) + (*y);
    return &z;
}

int a = 1, b = 2;
int *p = sum_returning_pointer(&a, &b);
printf("Sum = %d\n", *p);

// free the memory
free(p);
p = NULL;
```

**Issue with Above Implementation:**

-   In the program stack memory, after the execution of `sum_returning_pointer()`, memory allocated for it's local vars gets deallocated.
-   **Content of the address of z now have a garbage value.**

```text
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

After Execution of sum_returning_pointer:

            Program Stack Memory
-------------------------------------------------
|       main(int *argc, char *argv[])           |
|           int *argc; char *argv[],            |
|            int *p, a, b;                      |
-------------------------------------------------
```

**Solution:**

-   Using the heap memory or other solution can be making z a global variable.
-   If we're using a heap memory, DMA.
-   Doing so, the z get's stored in the program heap memory whose allocation/deallocation can be controlled by programmer.
-   i.e. **z doesn't gets deallocated once the function finished execution.**

```c
int *sum_returning_pointer_dma(int *x, int *y)
{
    // allocate the z in heap.
    int *z = (int *)malloc(sizeof(int));
    *z = *x + *y;
    return z;
}


int a = 1, b = 2;

// p now points to the address in heap memory
int *p = sum_returning_pointer_dma(&a, &b);
printf("Sum = %d\n", *p); // 3

// free the memory
free(p);
p = NULL;
```
