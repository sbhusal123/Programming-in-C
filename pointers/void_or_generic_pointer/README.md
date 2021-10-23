# Void Pointer

-   Also known as generic pointer.
-   Cannot be dereferenced. `*p` not allowed.
-   However increamenting (p+1) and decreamenting (p-1) is allowed.
-   In the lower version of gcc, pointer arithmetic with void pointer was not allowed.

```c
int x = 5;

int *p = &x;

// Void pointer decleration
void *p0;

// *p -> Not allowed

// Assignment
p0 = p;

// Pointer arithmetic is allowed in version above 7.3.0.
// p0 + 1
// p0 - 1
```
