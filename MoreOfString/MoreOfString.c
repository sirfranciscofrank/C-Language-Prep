#include <stdio.h>
#include <string.h>

/* ── 7.1 String Literals ── */
void string_literals(void)
{
    printf("Hello, world!\n");
    printf("This is a test.\n");
    printf("She said, \"It does.\"\n");
}

/* ── 7.2 String Variables (char*) ── */
void string_variables(void)
{
    char *s = "Hello, world!";
    printf("%s\n", s);
}

/* ── 7.3 String Variables as Arrays ── */
void string_as_array(void)
{
    char s[] = "Hello, world!";

    for (int i = 0; i < 13; i++)
        printf("%c", s[i]);
    printf("\n");

    /* char* also supports array indexing */
    char *p = "Hello, world!";
    for (int i = 0; i < 13; i++)
        printf("%c", p[i]);
    printf("\n");
}

/* ── 7.4 String Initializers: mutable vs read-only ── */
void string_initializers(void)
{
    /* Array copy — mutable */
    char t[] = "Hello, again!";
    t[0] = 'z';
    printf("%s\n", t);   /* "zello, again!" */

    /* Pointer to literal — DO NOT mutate */
    /* char *s = "Hello, world!"; s[0] = 'z'; // undefined behavior / crash */
}

/* ── 7.5 & 7.6 String Length and NUL Termination ── */
int my_strlen(char *s)
{
    int count = 0;
    while (s[count] != '\0')
        count++;
    return count;
}

void string_length(void)
{
    char *s = "Hello, world!";

    /* Built-in strlen() — returns size_t, print with %zu */
    printf("strlen:    %zu bytes\n", strlen(s));

    /* Our own implementation */
    printf("my_strlen: %d bytes\n", my_strlen(s));

    /* NUL terminator is implicit in every string literal */
    char explicit[] = {'H','i','!','\0'};   /* same as char[] = "Hi!" */
    printf("explicit: %s (%zu bytes)\n", explicit, strlen(explicit));
}

/* ── 7.7 Copying Strings ── */
void string_copy(void)
{
    char s[] = "Hello, world!";
    char t[100];

    /* Assignment only copies the pointer — both point to same memory */
    char *alias = s;
    alias[0] = 'z';
    printf("After alias mutation, s = %s\n", s);   /* "zello, world!" */
    s[0] = 'H';                                     /* restore */

    /* strcpy: destination first, source second (mirrors dst = src) */
    strcpy(t, s);
    t[0] = 'z';

    printf("s (original): %s\n", s);   /* "Hello, world!" */
    printf("t (copy):     %s\n", t);   /* "zello, world!" */
}

int main(void)
{
    printf("── 7.1 String Literals ──\n");
    string_literals();

    printf("\n── 7.2 String Variables ──\n");
    string_variables();

    printf("\n── 7.3 String as Array ──\n");
    string_as_array();

    printf("\n── 7.4 Mutable vs Read-Only ──\n");
    string_initializers();

    printf("\n── 7.5/7.6 Length & NUL Terminator ──\n");
    string_length();

    printf("\n── 7.7 Copying Strings ──\n");
    string_copy();

    return 0;
}