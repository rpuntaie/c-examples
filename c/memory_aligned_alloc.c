/*
gcc -std=c99 -pthread -o ../_build/c/memory_aligned_alloc.exe ./c/memory_aligned_alloc.c && (cd ../_build/c/;./memory_aligned_alloc.exe)
https://en.cppreference.com/w/c/memory/aligned_alloc
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *p1 = malloc(10*sizeof *p1);
    printf("default-aligned addr:   %p\n", (void*)p1);
    free(p1);
    int *p2 = aligned_alloc(1024, 1024*sizeof *p2);
    printf("1024-byte aligned addr: %p\n", (void*)p2);
    free(p2);
}

