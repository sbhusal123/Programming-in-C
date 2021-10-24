#include <stdio.h>
#include <string.h>

struct employee
{
    int age;
    char name[20];
};

typedef struct employee emp_struct;

void printStruct(emp_struct emp)
{
    // This causes extra memory allocation for existing structure.
    // printf("Size of pointer: %d\n", sizeof(emp));
    // printf("Address of struct in func: %d\n", &emp);
    printf("Name=%s\n", (emp).name);
    printf("Age=%d\n", (emp).age);
};

void printStructPassingPointer(emp_struct *ptr)
{
    printf("Size of pointer: %d\n", sizeof(ptr));
    printf("Name=%s\n", (*ptr).name);
    printf("Age=%d\n", (*ptr).age);
};

void main(void)
{
    struct employee emp1;
    emp1.age = 50;
    strcpy(emp1.name, "Surya");
    // printf("Address of struct in main: %d\n", &emp1);
    // printStruct(emp1);

    printStructPassingPointer(&emp1);
}
