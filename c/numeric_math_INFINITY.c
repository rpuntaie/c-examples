/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_INFINITY.exe ./c/numeric_math_INFINITY.c && (cd ../_build/c/;./numeric_math_INFINITY.exe)
https://en.cppreference.com/w/c/numeric/math/INFINITY
*/
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
int main(void)
{
    double f = INFINITY;
    uint64_t fn; memcpy(&fn, &f, sizeof f);
    printf("INFINITY:   %f %" PRIx64 "\n", f, fn);
}

