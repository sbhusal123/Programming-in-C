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

int main(int *argc, char *argv[])
{
    two_d_array_deref_address();
    return 0;
}