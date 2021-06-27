/*
gcc -std=c99 -pthread -o ../_build/c/types_offsetof.exe ./c/types_offsetof.c && (cd ../_build/c/;./types_offsetof.exe)
https://en.cppreference.com/w/c/types/offsetof
*/
#include <stdio.h>
#include <stddef.h>
struct S {
    char c;
    double d;
};
int main(void)
{
    printf("the first element is at offset %zu\n", offsetof(struct S, c));
    printf("the double is at offset %zu\n", offsetof(struct S, d));
}

