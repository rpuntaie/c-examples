/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/types_size_t.exe ./c/types_size_t.c && (cd ../_build/c/;./types_size_t.exe)
https://en.cppreference.com/w/c/types/size_t
*/
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
int main(void)
{
    const size_t N = 100;
    int numbers[N];
    for (size_t ndx = 0; ndx < N; ++ndx)
        numbers[ndx] = ndx;
    printf("SIZE_MAX = %zu\n", SIZE_MAX);
    size_t size = sizeof numbers;
    printf("size = %zu\n", size);
}

