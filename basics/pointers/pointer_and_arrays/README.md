# Passing array to the function:

-   Array are always passed by reference on function.
-   I.e. while passing an array, the address of an item is passed, not an array itself.

**Passing array as a pointer**

```c
void sum(int arr*, int size){
    /*
        ------ Address---------------
          &arr[0] = arr + 0 = 201
          &arr[1] = arr + 1 = 205
          &arr[2] = arr + 2 = 209
        -----------------------------

        -----Dereferening arr--------
          *(arr+0) = arr[0] = 1
          *(arr+1) = arr[1] = 2
          *(arr+2) = arr[2] = 3
        -----------------------------
    */

}

int x[3] =     {1,          2,          3}
// M/M addr:   201         205         209

// &x = 201
// &x + 1 = 205
// &x + 2 = 205

sum(&x, 3); // note that we are passing address of pointer
```

**Passing an array**

-   Array is always passed as a reference.

```c
void sum(int arr[], int size){
    /*
        ------ Address---------------
          &arr[0] = arr + 0 = 201
          &arr[1] = arr + 1 = 205
          &arr[2] = arr + 2 = 209
        -----------------------------

        -----Dereferening arr--------
          *(arr+0) = arr[0] = 1
          *(arr+1) = arr[1] = 2
          *(arr+2) = arr[2] = 3
        -----------------------------
    */

}

int x[3] =     {1,          2,          3}
// M/M addr:   201         205         209

// &x = 201
// &x + 1 = 205
// &x + 2 = 205

sum(x, 3); // note that we are passing array itself
```

> **Thus the compiler interprets: int arr[] as int \*arr**
