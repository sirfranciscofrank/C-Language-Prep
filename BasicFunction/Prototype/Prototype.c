#include <stdio.h>

int multiply(int a, int b);   // prototype — compiler knows it exists

int main(void)
{
    int result = multiply(4, 5);      // can call it before the definition
    printf("Product: %d\n", result);  // 20
}

int multiply(int a, int b)   // actual definition down here
{
    return a * b;
}
