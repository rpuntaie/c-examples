/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_for_3.exe ./c/language_for_3.c && (cd ../_build/c/;./language_for_3.exe)
https://en.cppreference.com/w/c/language/for
*/
#include <stdio.h>
#include <stdlib.h>
enum { SIZE = 8 };
int main(void)
{
    int array[SIZE];
    for(size_t i = 0 ; i < SIZE; ++i)
        array [i] = rand() % 2;
    printf("Array filled!\n");
    for (size_t i = 0; i < SIZE; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

