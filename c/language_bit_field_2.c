/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_bit_field_2.exe ./c/language_bit_field_2.c && (cd ../_build/c/;./language_bit_field_2.exe)
https://en.cppreference.com/w/c/language/bit_field
*/
#include <stdio.h>
struct S {
    // will usually occupy 8 bytes:
    // 5 bits: value of b1
    // 27 bits: unused
    // 6 bits: value of b2
    // 15 bits: value of b3
    // 11 bits: unused
    unsigned b1 : 5;
    unsigned :0; // start a new unsigned int
    unsigned b2 : 6;
    unsigned b3 : 15;
};
int main(void)
{
    printf("%zu\n", sizeof(struct S)); // usually prints 8
}

