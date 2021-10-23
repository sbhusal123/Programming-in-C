#include <stdio.h>

int sum_of_array_by_passing_pointer(int *arr, int size)
{
    int sum = 0;

    printf("-----------------Address in func--------------\n");
    for (int i = 0; i < size; i++)
        // printf("Address of  arr[%d]=%d\n", i, &arr[i]);
        printf("Address of  arr[%d]=%d\n", i, arr + i);
    printf("----------------------------------------------");

    for (int i = 0; i < size; i++)
        // sum += arr[i]; also works fine
        sum += *(arr + i);

    return sum;

    /*
        Enter the size: 3

        Enter 1 item: 4
        Enter 2 item: 1
        Enter 3 item: 8


        -----------------Address in main--------------
        Address of  arr[0]=-9696
        Address of  arr[1]=-9692
        Address of  arr[2]=-9688
        ----------------------------------------------

        -----------------Address in func--------------
        Address of  arr[0]=-9696
        Address of  arr[1]=-9692
        Address of  arr[2]=-9688
        ----------------------------------------------

        Sum=13
    */
}

int sum_of_array_passing_array(int arr[], int size)
{
    int sum = 0;

    printf("-----------------Address in func--------------\n");
    for (int i = 0; i < size; i++)
        // printf("Address of  arr[%d]=%d\n", i, &arr[i]);
        printf("Address of  arr[%d]=%d\n", i, arr + i);
    printf("----------------------------------------------");

    for (int i = 0; i < size; i++)
        // sum += *(arr + i); also works fine
        sum += arr[i];

    return sum;

    /*
        Enter the size: 2

        Enter 1 item: 6
        Enter 2 item: 9


        -----------------Address in main--------------
        Address of  arr[0]=-9696
        Address of  arr[1]=-9692
        ----------------------------------------------

        -----------------Address in func--------------
        Address of  arr[0]=-9696
        Address of  arr[1]=-9692
        ----------------------------------------------

        Sum=15
    */
}

int main(int *argc, char *argv[])
{
    int size = 0, sum;

    printf("Enter the size: ");
    scanf("%d", &size);

    printf("\n");
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter %d item: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\n\n");

    printf("-----------------Address in main--------------\n");
    for (int i = 0; i < size; i++)
        printf("Address of  arr[%d]=%d\n", i, &arr[i]);
    printf("----------------------------------------------\n\n");

    sum = sum_of_array_passing_array(arr, size); // notice we are not passing the address
    printf("\n\nSum=%d\n\n", sum);

    return 0;
}