#include <stdio.h>

void increment(int *p)
{
    *p = *p + 1;   // modifies the original variable via dereference
}

int main(void)
{
    int i = 10;
    increment(&i); // pass the address of i
    printf("%d\n", i); // prints 11
}
