/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_atan.exe ./c/numeric_math_atan.c && (cd ../_build/c/;./numeric_math_atan.exe)
https://en.cppreference.com/w/c/numeric/math/atan
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("atan(1) = %f, 4*atan(1)=%f\n", atan(1), 4*atan(1));
    // special values
    printf("atan(Inf) = %f, 2*atan(Inf) = %f\n", atan(INFINITY), 2*atan(INFINITY));
    printf("atan(-0.0) = %+f, atan(+0.0) = %+f\n", atan(-0.0), atan(0));
}

