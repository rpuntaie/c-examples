/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/types_integer_1.exe ./c/types_integer_1.c && (cd ../_build/c/;./types_integer_1.exe)
https://en.cppreference.com/w/c/types/integer
*/
#include <stdio.h>
#include <inttypes.h>
int main(void)
{
    printf("%zu\n", sizeof(int64_t));
    printf("%s\n", PRId64);
    printf("%+"PRId64"\n", INT64_MIN);
    printf("%+"PRId64"\n", INT64_MAX);
    int64_t n = 7;
    printf("%+"PRId64"\n", n);
}

