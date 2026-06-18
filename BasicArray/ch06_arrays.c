#include <stdio.h>

/* ============================================================
   6.1  Easy Example
   ============================================================ */
void section_6_1(void)
{
    printf("=== 6.1 Easy Example ===\n");

    int i;
    float f[4];          // declare an array of 4 floats

    f[0] = 3.14159f;     // index starts at 0
    f[1] = 1.41421f;
    f[2] = 1.61803f;
    f[3] = 2.71828f;

    for (i = 0; i < 4; i++)
        printf("f[%d] = %f\n", i, f[i]);

    printf("\n");
}

/* ============================================================
   6.2  Getting the Length of an Array
   ============================================================ */
void section_6_2(void)
{
    printf("=== 6.2 Getting Array Length with sizeof ===\n");

    int x[12];

    printf("sizeof x          = %zu bytes\n", sizeof x);
    printf("sizeof(int)       = %zu bytes\n", sizeof(int));
    printf("element count     = %zu\n", sizeof x / sizeof(int));

    /* sizeof trick only works in the same scope where array is declared.
       Once passed to a function the array decays to a pointer and the
       trick gives the pointer size, NOT the array size. */
    printf("sizeof(double[48])= %zu bytes\n", sizeof(double[48]));

    printf("\n");
}

/* ============================================================
   6.3  Array Initializers
   ============================================================ */
#define COUNT 5

void section_6_3(void)
{
    printf("=== 6.3 Array Initializers ===\n");

    /* basic initializer */
    int a[5] = {22, 37, 3490, 18, 95};
    printf("Full initializer:  ");
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");

    /* fewer values — rest become 0 */
    int b[5] = {22, 37, 3490};
    printf("Partial (rest 0):  ");
    for (int i = 0; i < 5; i++) printf("%d ", b[i]);
    printf("\n");

    /* zero-out entire array */
    int c[100] = {0};
    printf("Zero array [0]=%d [50]=%d [99]=%d\n", c[0], c[50], c[99]);

    /* designated / index-based initializer */
    int d[10] = {0, 11, 22, [5]=55, 66, 77};
    printf("Designated:        ");
    for (int i = 0; i < 10; i++) printf("%d ", d[i]);
    printf("\n");

    /* designated with a #define */
    int e[COUNT] = {[COUNT-3]=3, 2, 1};
    printf("With #define:      ");
    for (int i = 0; i < COUNT; i++) printf("%d ", e[i]);
    printf("\n");

    /* let the compiler count the elements */
    int f[] = {22, 37, 3490};
    printf("Auto-size len=%zu: ", sizeof f / sizeof f[0]);
    for (int i = 0; i < (int)(sizeof f / sizeof f[0]); i++)
        printf("%d ", f[i]);
    printf("\n\n");
}

/* ============================================================
   6.4  Out of Bounds  (undefined behaviour — shown for education)
   ============================================================ */
void section_6_4(void)
{
    printf("=== 6.4 Out of Bounds (first 5 valid, rest UB) ===\n");

    int a[5] = {22, 37, 3490, 18, 95};

    /* Only print the valid range; reading beyond is undefined behaviour */
    for (int i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);

    printf("(Skipping indices 5-9 — accessing them is undefined behaviour)\n\n");
}

/* ============================================================
   6.5  Multidimensional Arrays
   ============================================================ */
void section_6_5(void)
{
    printf("=== 6.5 Multidimensional Arrays ===\n");

    int row, col;
    int a[2][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}
    };

    for (row = 0; row < 2; row++)
        for (col = 0; col < 5; col++)
            printf("a[%d][%d] = %d\n", row, col, a[row][col]);

    /* 3x3 identity matrix using designated initializer */
    int id[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
    printf("3x3 identity:\n");
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++)
            printf("%d ", id[row][col]);
        printf("\n");
    }
    printf("\n");
}

/* ============================================================
   6.6.1  Getting a Pointer to an Array
   ============================================================ */
void section_6_6_1(void)
{
    printf("=== 6.6.1 Pointer to an Array ===\n");

    int a[5] = {11, 22, 33, 44, 55};
    int *p;

    p = &a[0];   // explicit: address of first element
    printf("via &a[0]: *p = %d\n", *p);

    p = a;       // shorthand — same thing
    printf("via  a   : *p = %d\n", *p);

    printf("\n");
}

/* ============================================================
   6.6.2  Passing Single Dimensional Arrays to Functions
   All three signatures below are identical to the compiler.
   ============================================================ */
void times2(int *a, int len)          // pointer notation
{
    for (int i = 0; i < len; i++)
        printf("%d ", a[i] * 2);
    printf("\n");
}

void times3(int a[], int len)         // unsized array notation
{
    for (int i = 0; i < len; i++)
        printf("%d ", a[i] * 3);
    printf("\n");
}

void times4(int a[5], int len)        // sized array notation (size ignored)
{
    for (int i = 0; i < len; i++)
        printf("%d ", a[i] * 4);
    printf("\n");
}

void section_6_6_2(void)
{
    printf("=== 6.6.2 Passing 1-D Arrays to Functions ===\n");

    int x[5] = {11, 22, 33, 44, 55};

    printf("times2: "); times2(x, 5);
    printf("times3: "); times3(x, 5);
    printf("times4: "); times4(x, 5);

    printf("\n");
}

/* ============================================================
   6.6.3  Changing Arrays in Functions
   ============================================================ */
void double_array(int *a, int len)
{
    for (int i = 0; i < len; i++)
        a[i] *= 2;   // modifies the original array in the caller
}

void section_6_6_3(void)
{
    printf("=== 6.6.3 Changing Arrays in Functions ===\n");

    int x[5] = {1, 2, 3, 4, 5};

    printf("before: ");
    for (int i = 0; i < 5; i++) printf("%d ", x[i]);
    printf("\n");

    double_array(x, 5);

    printf("after : ");
    for (int i = 0; i < 5; i++) printf("%d ", x[i]);
    printf("\n\n");
}

/* ============================================================
   6.6.4  Passing Multidimensional Arrays to Functions
   The first dimension can be omitted; all others must be given.
   ============================================================ */
void print_2D_array(int a[][3], int rows)   // first dim omitted, ok
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}

void section_6_6_4(void)
{
    printf("=== 6.6.4 Passing 2-D Arrays to Functions ===\n");

    int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_2D_array(x, 2);
    printf("\n");
}

/* ============================================================
   main — runs every section in order
   ============================================================ */
int main(void)
{
    section_6_1();
    section_6_2();
    section_6_3();
    section_6_4();
    section_6_5();
    section_6_6_1();
    section_6_6_2();
    section_6_6_3();
    section_6_6_4();

    return 0;
}
