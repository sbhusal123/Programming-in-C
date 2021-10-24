# Structures

-   Holds several data items of same kind.

**Declaration Syntax:**

```c
struct <name>{
    <type1> <name1>;
    <type2> <name2>;
    ........
}
```

**Example:**

```c
struct employee{
    int id;
    int age;
    char name[10];
}

// defining type
typedef struct employee emp_type;


// usage
struct employee emp;
//or
// emp_type emp1;

emp.id = 2422;
emp.age = 32;
strcpy(emp, "Jane Doe");
```

## Caveats: Memory allocated for structure

-Note that 1 byte=8bit

**i. Memory In 32bits archutecture**

-   Each memory segment is of 32 bits / 4 bytes.
-   Data items greater than 32 bits/ 4bytes are stored in the subscequent segment.

```text

    Memory in 32 bit mode
-----------------------------
|          Segment1         | ----|
-----------------------------     |-----> Can store upto 32 bits / 4 bytes of data.
|          Segment2         | ----|
-----------------------------
```

**Consider the structure:**

```c
struct foo{
    int bar1;
    char bar2[2];
}

typedef struct foo foo_struct;

printf("Size of struct: %d", sizeof(struct)); // 8 bytes
```

**Expected Size =** `1 * sizeof(int) + 2 * sizeof(char) = 4 + 2 =6`

-   In the typical 32 bit mode. Memory address is of 4 bytes.
-   Thus once half or any amount of 4 bytes is allocated, remaining cannot be used again.

```c
struct foo{
    int bar1; // 4 bytes = 32 bit -> 1 segment is occupied
    char bar2[2]; // 2 bytes
                  // 2 bytes padding -> cause it can't be used again
}

-----------------------------------------------------
|      bar1 (4 bytes = 32 bits)                     |
-----------------------------------------------------
|    bar2 (2 bytes)   |      Remaining (2 bytes)    |
-----------------------------------------------------
```

-   Here remaining two bytes cannot be used. So these portion of memory is used as padding.
-   This causes remaining size also to be used by the struct.
