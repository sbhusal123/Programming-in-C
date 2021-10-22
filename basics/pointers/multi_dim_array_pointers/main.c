#include <stdio.h>

void two_d_array_deref_address()
{
    int x[2][3] = {
        {1, 2, 3}, {4, 5, 6}};

    int(*p)[3];
    printf("x[2][3] = { {1, 2, 3}, {4, 5, 6} }\n");
    printf("\n\n");

    printf("--------- Address of each element -------------\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("&x[%d][%d]=%d\n", i, j, &x[i][j]);
        }
    }
    printf("------------------------------------------------");

    printf("\n\n");

    printf("------------------ Address &x[i] --------------\n");
    printf("&x[0]=%d\n", &x[0]);
    printf("&x[1]=%d\n", &x[1]);
    printf("------------------------------------------------");

    printf("\n\n");
    printf("------------------ Content x[i] ---------------\n");
    printf("x[0]=%d\n", x[0]);
    printf("x[1]=%d\n", x[1]);
    printf("------------------------------------------------\n");

    printf("\n\n");
    printf("------------------ Dereferenced *x[i] ----------\n");
    printf("*x[0]=%d\n", *x[0]);
    printf("*x[1]=%d\n", *x[1]);
    printf("------------------------------------------------");

    printf("\n\n");

    /*   Output

            x[2][3] = { {1, 2, 3}, {4, 5, 6} }


            --------- Address of each element -------------
            &x[0][0]=-9648
            &x[0][1]=-9644
            &x[0][2]=-9640
            &x[1][0]=-9636
            &x[1][1]=-9632
            &x[1][2]=-9628
            ------------------------------------------------

            ------------------ Address &x[i] --------------
            &x[0]=-9648
            &x[1]=-9636
            ------------------------------------------------

            ------------------ Content x[i] ---------------
            x[0]=-9648
            x[1]=-9636
            ------------------------------------------------


            ------------------ Dereferenced *x[i] ----------
            *x[0]=1
            *x[1]=4
            ------------------------------------------------
    */
}

void two_d_array_pointer()
{
    int x[2][3] = {
        {1, 2, 3}, {4, 5, 6}};

    int(*p)[3] = &x;

    printf("int x[2][3] = { {1, 2, 3}, {4, 5, 6} }\n");
    printf("int(*p)[3]=&x\n");
    printf("\n\n");

    printf("--------- Address of each element -------------\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("&x[%d][%d]=%d\n", i, j, &x[i][j]);
        }
    }
    printf("------------------------------------------------");

    printf("\n\n");

    printf("--------- Address of &p[i][j] ----------------\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("&p[%d][%d]=%d\n", i, j, &p[i][j]);
        }
    }
    printf("------------------------------------------------");
    printf("\n\n");

    printf("--------- Address of p[i]+j ----------------\n");
    for (int i = 0; i < 2; i++)
    {
        printf("p[0]+j=%d\n", i, p[0] + i);
    }
    printf("------------------------------------------------");
    printf("\n\n");

    printf("------------- Add &p[i] ----------------------\n");
    for (int i = 0; i < 2; i++)
    {
        printf("&p[%d]=%d \n", i, &p[i]);
    }
    printf("------------------------------------------------");

    printf("\n\n");

    /*
    Output:

        int x[2][3] = { {1, 2, 3}, {4, 5, 6} }
        int(*p)[3]=&x


        --------- Address of each element -------------
        &x[0][0]=-9648
        &x[0][1]=-9644
        &x[0][2]=-9640
        &x[1][0]=-9636
        &x[1][1]=-9632
        &x[1][2]=-9628
        ------------------------------------------------

        --------- Address of &p[i][j] ----------------
        &p[0][0]=-9648
        &p[0][1]=-9644
        &p[0][2]=-9640
        &p[1][0]=-9636
        &p[1][1]=-9632
        &p[1][2]=-9628
        ------------------------------------------------

        --------- Address of p[i]+j ----------------
        p[0]+j=0
        p[0]+j=1
        ------------------------------------------------

        ------------- Add &p[i] ----------------------
        &p[0]=-9648
        &p[1]=-9636
        ------------------------------------------------
    */
}

void inplace_increament(int *arr, int size_x, int size_y, int inc_by)
{
    // Inplace increament at memory location
    for (int i = 0; i < size_x; i++)
        for (int j = 0; j < size_y; j++)
            *(&arr[i] + j) += inc_by;
}

int main(int *argc, char *argv[])
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    printf("\n");
    printf("Before increament\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            printf("arr[%d][%d]=%d \n", i, j, arr[i][j]);

    // Inplace increament by
    inplace_increament(&arr, 2, 3, 2);

    printf("\n\n");
    printf("After increament\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            printf("arr[%d][%d]=%d \n", i, j, arr[i][j]);

    printf("\n");

    /*
        Before increament
        arr[0][0]=1 
        arr[0][1]=2 
        arr[0][2]=3 
        arr[1][0]=4 
        arr[1][1]=5 
        arr[1][2]=6 


        After increament
        arr[0][0]=3 
        arr[0][1]=6 
        arr[0][2]=7 
        arr[1][0]=6 
        arr[1][1]=5 
        arr[1][2]=6 
    */
    return 0;
}