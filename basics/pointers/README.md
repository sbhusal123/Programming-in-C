# Pointers

-   Variable used to store the memory address of other variables

![asd](https://i.ibb.co/T8nhc5x/a-drawio.png)

-   **Initialization / Declare pointer variable:** `<type> *p;`
    -   for example `int *p` stores the location of integer variable.
-   **Assign address:** `p = &a`
-   **De-referencing:** `*p`. Gives value of the memory location pointed to.

```text
int a;

int *p; // pointer variable declaration, pointer to integer

a = 10;

p = &a; // asign p, the address of a

printf(p) // 207

printf(&a) // 207

printf(&p) // 202

print(*p) // 10 -> Dereferencing

// UPdate value using pointer
*p = 8
print(a) // 8
```

-   To point to integer variable we need integer type pointer. `int *p`
-   To point to char variable we need char type pointer. `char *p`
-   i.e. to point to particular data type, we need a pointer type corresponding to the data type.

```c
int a; // integer
int *p; // pointer to integer

char c; //character
char *cp; //pointer to character

double d; // double
char *dp; //pointer to double
```
