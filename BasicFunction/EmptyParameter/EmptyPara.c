#include <stdio.h>

void say_hello(void)     // void = takes nothing
{
    printf("Hello!\n");
}

void print_line(void)
{
    printf("----------\n");
}

int main(void)
{
    print_line();   // no arguments to pass
    say_hello();
    print_line();
}
