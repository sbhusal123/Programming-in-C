#include <stdio.h>
#include <string.h>

#define NAME_SIZE 30

struct employee
{
    char name[NAME_SIZE];
    int age;
};

typedef struct employee emp;

void main(void)
{
    /*
        Can also be defined using custom type as:
        emp e;
    */
    struct employee e;

    e.age = 10;
    // Array of character cannot be directly assigned.
    // char x[2] = [ '1', '2' ]; -> Not allowed
    strcpy(e.name, "surya");

    printf("Name = %s\n", e.name);

    printf("Size of structure=%d", sizeof(e));
}