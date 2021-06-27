/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_asinh.exe ./c/numeric_math_asinh.c && (cd ../_build/c/;./numeric_math_asinh.exe)
https://en.cppreference.com/w/c/numeric/math/asinh
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("asinh(1) = %f\nasinh(-1) = %f\n", asinh(1), asinh(-1));
    // special values
    printf("asinh(+0) = %f\nasinh(-0) = %f\n", asinh(0.0), asinh(-0.0));
}

