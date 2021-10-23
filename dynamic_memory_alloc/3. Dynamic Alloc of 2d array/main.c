#include <stdlib.h>
#include <stdio.h>

void allocate_2d_array()
{
    int row, col, i, j, count = 0;

    printf("Enter the rows: ");
    scanf("%d", &row);
    printf("Enter the cols: ");
    scanf("%d", &col);

    // Allocation for row, allocation using integer pointer type.
    int **arr = (int **)malloc(row * sizeof(int *));

    // allocation for cols, using integer type
    for (i = 0; i < row; i++)
        arr[i] = (int *)malloc(col * sizeof(int));

    // Insert value
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            arr[i][j] = count;
            count += 1;
        }
    }

    printf("Items\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("arr[%d][%d]=%d\n", i, j, arr[i][j]);
        }
    }

    // free memory allocated
    for (int i = 0; i < 2; i++)
        free(arr[i]);
}

int main(int *argc, char *argv[])
{
    allocate_2d_array();

    return 0;
}