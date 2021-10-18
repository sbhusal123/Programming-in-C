# Pointer Arithmetics

-   Addition / Increament
-   Subtraction / Decreament

**Operation With integer pointer:**

-   Size of int = 4 bytes
-   If integer pointer pi points to memory location 2001.
-   Then a+1 points to **2001 + size_of_int = 2005**

```c
int c = 5;

int* pi = &c; // if p = 2001H
printf("%d",pi+1); //2005H
```

**Operation with char pointer:**

-   Size of char = 1 byte.
-   If char pointer pc points to memory location 5002.
-   Then a-1 points to **2001 - size_of_int = 5001**

```c
char c = 'x';

char* ci = &c; // if p = 5002H
printf("%d",pc-1); //5001H
```
