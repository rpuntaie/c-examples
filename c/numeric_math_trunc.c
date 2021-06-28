/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_trunc.exe ./c/numeric_math_trunc.c && (cd ../_build/c/;./numeric_math_trunc.exe)
https://en.cppreference.com/w/c/numeric/math/trunc
*/
#include <math.h>
#include <stdio.h>
int main(void)
{
    printf("trunc(+2.7) = %+.1f\n", trunc(2.7));
    printf("trunc(-2.7) = %+.1f\n", trunc(-2.7));
    printf("trunc(-0.0) = %+.1f\n", trunc(-0.0));
    printf("trunc(-Inf) = %+f\n",   trunc(-INFINITY));
}

