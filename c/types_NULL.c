/*
gcc -std=c99 -pthread -o ../_build/c/types_NULL.exe ./c/types_NULL.c && (cd ../_build/c/;./types_NULL.exe)
https://en.cppreference.com/w/c/types/NULL
*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{    
    // any kind of pointer can be set to NULL
    int* p = NULL;
    struct S *s = NULL;
    void(*f)(int, double) = NULL;
    // many pointer-returning functions use null pointers to indicate error
    char *ptr = malloc(10);
    if (ptr == NULL) printf("Out of memory");
    free(ptr);
}

