/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language__Alignof.exe ./c/language__Alignof.c && (cd ../_build/c/;./language__Alignof.exe)
https://en.cppreference.com/w/c/language/_Alignof
*/
#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>
int main(void)
{
    printf("Alignment of char = %zu\n", alignof(char));
    printf("Alignment of max_align_t = %zu\n", alignof(max_align_t));
    printf("alignof(float[10]) = %zu\n", alignof(float[10]));
    printf("alignof(struct{char c; int n;}) = %zu\n",
            alignof(struct {char c; int n;}));    
}

