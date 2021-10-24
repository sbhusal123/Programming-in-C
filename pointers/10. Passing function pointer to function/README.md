# Passing Function pointer to function

**Definition:**

```c
// We want to pass this function as a pointer
int square(int x)
{
    return x * x;
}

// third argument is the pointer to the function square
int add(int x, int y, int (*callback_sqr)(int))
{
    int z = x + y;
    return callback_sqr(z);
}
```

**Usage:**

```
int x = 1, y = 2;
int z = add(x, y, &square); //passing the address of function square
printf("Sum of square: %d\n\n", z);
```
