# Pointer to MultiDimensional Array

**i. Decoding Two Dimensional Array:**

```c
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
```

**ii. Two Dimensional Array Pointer:**

-   Size of array = 2 \* 3
-   Can be thought of as a two slices with three sub slices in each.
-   **Pointer Initialization:** `int(*p)[<size_of_sub_slice>]=&x`

```text
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
```

**iii. Passing Two Dimensional Array Pointer to function:**

```text
<!-- function signature -->
void inplace_increament(int *arr, int size_x, int size_y, int inc_by)
// each element can be dereferenced as *(&arr[i] + j);

<!-- Array initialization -->
int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

<!-- Passing to function -->
inplace_increament(&arr, 2, 3, 2);
```
