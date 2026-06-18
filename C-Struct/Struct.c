// Struct.c — a guided tour of C structs
// Each section maps to a section in the chapter you read.
// Compile:  gcc -Wall -Wextra -o struct Struct.c
// Run:      ./struct

#include <stdio.h>
#include <string.h>   // for strcmp() in the comparison section

// 8.1 — Declaring a struct (at global scope so the whole file can see it).
// This creates a NEW TYPE whose full name is "struct car".
struct car {
    char *name;
    float price;
    int speed;
};

// 8.3 / 8.4 — Function that takes a POINTER to a struct so changes are
// visible back in the caller. We'll use the arrow operator inside.
void set_price(struct car *c, float new_price) {
    // c is a pointer, so we can't use the dot operator on it directly.
    // (*c).price = new_price;   // the clunky, explicit way
    c->price = new_price;        // the idiomatic arrow-operator way
}

// A helper that takes a pointer just to READ (no changes), purely to keep
// printing tidy. const says "I promise not to modify what c points to."
void print_car(const struct car *c) {
    printf("  Name:      %s\n", c->name);
    printf("  Price:     %.2f\n", c->price);
    printf("  Top Speed: %d km/h\n", c->speed);
}

// 8.6 — The only safe way to compare structs: field by field.
// Returns 1 if equal, 0 if not.
int cars_equal(const struct car *a, const struct car *b) {
    return strcmp(a->name, b->name) == 0  // compare the strings, not the pointers
        && a->price == b->price
        && a->speed == b->speed;
}

int main(void) {
    // --- 8.1: declare and set fields one at a time with the dot operator ---
    printf("== 8.1 Dot operator ==\n");
    struct car saturn;                 // uninitialized variable of type struct car
    saturn.name  = "Saturn SL/2";
    saturn.price = 15999.99;
    saturn.speed = 175;
    print_car(&saturn);

    // --- 8.2: initializers ---
    printf("\n== 8.2 Initializers ==\n");

    // Positional: values must match field order. Fragile if the struct changes.
    struct car positional = {"Honda Civic", 22000.00, 180};

    // Designated: name each field, order-independent and safer.
    // Any field you leave out (here, .price) is initialized to zero.
    struct car designated = {.speed = 200, .name = "Tesla Model 3"};

    printf("Positional init:\n");
    print_car(&positional);
    printf("Designated init (note price defaulted to 0):\n");
    print_car(&designated);

    // --- 8.3 / 8.4: pass a pointer so a function can mutate our struct ---
    printf("\n== 8.3/8.4 Passing a pointer + arrow operator ==\n");
    printf("Saturn price before: %.2f\n", saturn.price);
    set_price(&saturn, 799.99);        // &saturn is a struct car*
    printf("Saturn price after:  %.2f\n", saturn.price);

    // --- 8.5: copying a struct is a plain assignment (shallow copy) ---
    printf("\n== 8.5 Copying ==\n");
    struct car clone = saturn;         // every field copied as-is...
    // ...including the name POINTER. Both now point at the SAME string.
    printf("Clone is a field-by-field copy of saturn:\n");
    print_car(&clone);

    // --- 8.6: comparing structs, field by field ---
    printf("\n== 8.6 Comparing ==\n");
    printf("saturn vs clone equal?      %s\n",
           cars_equal(&saturn, &clone) ? "yes" : "no");
    printf("saturn vs positional equal? %s\n",
           cars_equal(&saturn, &positional) ? "yes" : "no");

    return 0;
}