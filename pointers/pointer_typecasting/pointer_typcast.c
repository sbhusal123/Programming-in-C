/*
    8 bit = 1 byte
       |--> 001 = 3 bit
    
    Q) Why so strong types for pointers (int, char) ?
    -> To deference (access/modify) values
*/

/*
- Size of char is 1 byte:
- If pointer p points to m/m address: 2021
- (p+1) points to address: 2022
*/

void pointer_typecasting()
{
    /*
        ------------ Purpose of this function. ---------------------------------------
            Given an integer of 4 byte: a b c d, where each letter represents the byte
            Prints the content of each byte a, b, c, d
        ------------------------------------------------------------------------------
    */

    /*
    --------------------- Concept ----------------------------------------------------
                int x; -> 4 byte
                4 byte      3 byte      2 byte      1 byte
                00000000    00000000    00000010    00000001
        Address:   203          202         201         200
        Value:     (+)           0          512          1

        Thus the value stored is: (512+1) = 513

        int *p;
        p = &x;
        p = 200 -> Always points to the beginning address.

        -> Last bit used to store sign bit. (Negative/positive)
        -> Rest 31 bits used to store the value


    ------------------------------------------------------------------------------
    */
    int a = 513;
    int *p;

    p = &a;

    printf("size of integer is %d bytes\n", sizeof(int));
    printf("Address pointed = %d, Value at address=%d\n\n", p, *p);

    char *pc; // pointer typecasting
    pc = (char *)p;
    printf("Size of char is %d bytes\n\n", sizeof(char));

    printf("Printing the cotent at each m/m location(byte) of integer.\n");
    // printf("Value at %d location = %d \n", pc + 3, *(pc + 3));
    // printf("Value at %d location = %d \n", pc + 2, *(pc + 2));
    // printf("Value at %d location = %d \n", pc + 1, *(pc + 1));
    // printf("Value at %d location = %d \n", pc, *pc);
    for (int i = 3; i >= 0; i--)
    {
        printf("Value at %d location = %d \n", pc + i, *(pc + i));
    }

    /*
        ----------------------- Output Interpretation -----------------
        size of integer is 4 bytes
        Address pointed = -9616, Value at address=513 

        Size of char is 1 bytes

        Printing the cotent at each m/m location(byte) of integer.
        Value at -9613 location = 0  // (00000000)
        Value at -9614 location = 0  // (00000000)
        Value at -9615 location = 2  // (00000010)
        Value at -9616 location = 1  // (00000001)
        --------------------------------------------------------------

    */
}

int main(int argc, char *argv[])
{

    pointer_typecasting();
    return 0;
}
