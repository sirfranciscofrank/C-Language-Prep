#include <stdio.h>

int main(void)
{
    int *p = NULL;  // pointer initialized to nothing

    // check before dereferencing - always safe practice
    if (p == NULL) {
        printf("p is not pointing at anything yet!\n");
    }

    int x = 42;
    p = &x;  // now p points to something real

    if (p != NULL) {
        printf("p is now pointing to: %d\n", *p);  // safe to dereference
    }
}
