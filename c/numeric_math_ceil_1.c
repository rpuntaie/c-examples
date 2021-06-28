/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_ceil_1.exe ./c/numeric_math_ceil_1.c && (cd ../_build/c/;./numeric_math_ceil_1.exe)
https://en.cppreference.com/w/c/numeric/math/ceil
*/
#include <math.h>
#include <stdio.h>
int main(void)
{
    printf("ceil(+2.4) = %+.1f\n", ceil(2.4));
    printf("ceil(-2.4) = %+.1f\n", ceil(-2.4));
    printf("ceil(-0.0) = %+.1f\n", ceil(-0.0));
    printf("ceil(-Inf) = %+f\n",   ceil(-INFINITY));
}

