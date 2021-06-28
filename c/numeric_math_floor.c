/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_floor.exe ./c/numeric_math_floor.c && (cd ../_build/c/;./numeric_math_floor.exe)
https://en.cppreference.com/w/c/numeric/math/floor
*/
#include <math.h>
#include <stdio.h>
int main(void)
{
    printf("floor(+2.7) = %+.1f\n", floor(2.7));
    printf("floor(-2.7) = %+.1f\n", floor(-2.7));
    printf("floor(-0.0) = %+.1f\n", floor(-0.0));
    printf("floor(-Inf) = %+f\n",   floor(-INFINITY));
}

