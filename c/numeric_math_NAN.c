/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_NAN.exe ./c/numeric_math_NAN.c && (cd ../_build/c/;./numeric_math_NAN.exe)
https://en.cppreference.com/w/c/numeric/math/NAN
*/
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
int main(void)
{
    double f = NAN;
    uint64_t fn; memcpy(&fn, &f, sizeof f);
    printf("NAN:   %f %" PRIx64 "\n", f, fn);
}

