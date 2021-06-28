/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_signbit.exe ./c/numeric_math_signbit.c && (cd ../_build/c/;./numeric_math_signbit.exe)
https://en.cppreference.com/w/c/numeric/math/signbit
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("signbit(+0.0) = %d\n", signbit(+0.0));
    printf("signbit(-0.0) = %d\n", signbit(-0.0));
}

