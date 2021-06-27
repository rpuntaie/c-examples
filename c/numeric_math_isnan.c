/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_isnan.exe ./c/numeric_math_isnan.c && (cd ../_build/c/;./numeric_math_isnan.exe)
https://en.cppreference.com/w/c/numeric/math/isnan
*/
#include <stdio.h>
#include <math.h>
#include <float.h>
int main(void)
{
    printf("isnan(NAN)         = %d\n", isnan(NAN));
    printf("isnan(INFINITY)    = %d\n", isnan(INFINITY));
    printf("isnan(0.0)         = %d\n", isnan(0.0));
    printf("isnan(DBL_MIN/2.0) = %d\n", isnan(DBL_MIN/2.0));
    printf("isnan(0.0 / 0.0)   = %d\n", isnan(0.0/0.0));
    printf("isnan(Inf - Inf)   = %d\n", isnan(INFINITY - INFINITY));
}

