#include <stdio.h>

int main(void) {
    int a = 10, b = 3;
    int i, j;

    // --- Arithmetic & Shorthand ---
    printf("=== Arithmetic ===\n");
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);     // Integer division
    printf("a %% b = %d\n", a % b);   // Modulo (remainder)

    // --- Ternary Operator ---
    printf("\n=== Ternary ===\n");
    printf("%d is %s\n", a, a % 2 == 0 ? "even" : "odd");
    printf("%d is %s\n", b, b % 2 == 0 ? "even" : "odd");

    // --- Pre vs Post Increment ---
    printf("\n=== Pre vs Post Increment ===\n");
    i = 10;
    j = 5 + i++;    // uses i=10, then increments
    printf("Post-increment: i=%d, j=%d\n", i, j);  // i=11, j=15

    i = 10;
    j = 5 + ++i;    // increments first, then uses i=11
    printf("Pre-increment:  i=%d, j=%d\n", i, j);  // i=11, j=16

    // --- Decrement ---
    printf("\n=== Decrement ===\n");
    i = 10;
    printf("Post-decrement: %d\n", i--);  // prints 10, then i=9
    printf("i after: %d\n", i);
    i = 10;
    printf("Pre-decrement:  %d\n", --i);  // i=9, prints 9
    printf("i after: %d\n", i);

    // --- Sizeof ---
    printf("\n=== sizeof ===\n");
    printf("sizeof(int)    = %zu bytes\n", sizeof(int));
    printf("sizeof(char)   = %zu bytes\n", sizeof(char));
    printf("sizeof(double) = %zu bytes\n", sizeof(double));
    printf("sizeof(a)      = %zu bytes\n", sizeof a);

    // --- Comma Operator in for loop ---
    printf("\n=== Comma in for loop ===\n");
    for (i = 0, j = 10; i < 5; i++, j--) {
        printf("i=%d, j=%d\n", i, j);
    }

    // --- Boolean / Conditional ---
    printf("\n=== Conditionals ===\n");
    if (a > b)
        printf("%d > %d is true\n", a, b);

    if (a != b)
        printf("%d != %d is true\n", a, b);

    if (a >= 10 && b < 5)
        printf("a >= 10 AND b < 5\n");

    if (!(a == b))
        printf("a and b are NOT equal\n");

    return 0;
}
