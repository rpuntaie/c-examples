/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_isfinite.exe ./c/numeric_math_isfinite.c && (cd ../_build/c/;./numeric_math_isfinite.exe)
https://en.cppreference.com/w/c/numeric/math/isfinite
*/
#include <stdio.h>
#include <math.h>
#include <float.h>
int main(void)
{
    printf("isfinite(NAN)         = %d\n", isfinite(NAN));
    printf("isfinite(INFINITY)    = %d\n", isfinite(INFINITY));
    printf("isfinite(0.0)         = %d\n", isfinite(0.0));
    printf("isfinite(DBL_MIN/2.0) = %d\n", isfinite(DBL_MIN/2.0));
    printf("isfinite(1.0)         = %d\n", isfinite(1.0));
    printf("isfinite(exp(800))    = %d\n", isfinite(exp(800)));
}

