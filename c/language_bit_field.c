/*
gcc -std=c99 -pthread -o ../_build/c/language_bit_field.exe ./c/language_bit_field.c && (cd ../_build/c/;./language_bit_field.exe)
https://en.cppreference.com/w/c/language/bit_field
*/
#include <stdio.h>
struct S {
 // three-bit unsigned field,
 // allowed values are 0...7
 unsigned int b : 3;
};
int main(void)
{
    struct S s = {7};
    ++s.b; // unsigned overflow
    printf("%d\n", s.b); // output: 0
}

