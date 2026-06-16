#include <stdio.h>

void math(int *sum, int *product, int a, int b)
{
    *sum     = a + b;
    *product = a * b;
}

int main(void)
{
    int s, p;
    math(&s, &p, 3, 4);
    printf("Sum: %d\n", s);      
    printf("Product: %d\n", p);  
}
