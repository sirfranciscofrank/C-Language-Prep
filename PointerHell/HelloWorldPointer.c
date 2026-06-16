#include <stdio.h>

int main(void)
{
    char *p = "hello world";  // p points to the start of the string

    printf("%s\n", p);        // prints: hello world
    printf("%p\n", p);        // prints: some address like 0x...
}
