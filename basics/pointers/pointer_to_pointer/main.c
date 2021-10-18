int main(int argc, char *argv[])
{
    int x = 5;

    int *p1;
    p1 = &x;

    int **p2;
    p2 = &p1;

    printf("Content at address of pointer: (*p1=%d)\n", *p1);
    printf("Value of pointer p1: (p=%d)\n", p1);
    printf("Address of pointer p1: (&p1=%d)\n\n", &p1);

    printf("Value of pointer p2 pointing to p1: (p2= %d)\n", p2);
    printf("*p2= %d\n", *p2);
    printf("Content at address of pointer p2: (**p2p=%d)\n\n", **p2);

    return 0;
}