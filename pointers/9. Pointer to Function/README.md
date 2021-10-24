# Pointer to function

-   Pointer pointing to the function.

**Declaration Syntax:**

-   `<return_type>* (<type1>, <type2>) = func`

If we have a function

```c
// function to which we want to point
int sum_of_two_numbers(int x, int y);
void sum(int x, int y);
void foo();
```

**Syntax 1:**

```c
// declaring and assigning the pointer
int (*sum_of_two_numbers_ptr)(int, int) = sum_of_two_numbers;
void (*sum_ptr)(int, int) = sum;
void (*foo_ptr)() = foo;

// usage
int z = sum_of_two_numbers_ptr(1, 2);
sum_ptr(1, 2);
foo_ptr();
```

**Syntax 2:**

```c
// declaring and assigning the pointer
int (*sum_of_two_numbers_ptr)(int, int) = &sum_of_two_numbers;
void (*sum_ptr)(int, int) = &sum;
void (*foo_ptr)() = &foo;

// usage
int z = (*sum_of_two_numbers_ptr)(1, 2);
(*sum_ptr)(1, 2);
(*foo_ptr)()
```
