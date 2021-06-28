/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_tanh.exe ./c/numeric_math_tanh.c && (cd ../_build/c/;./numeric_math_tanh.exe)
https://en.cppreference.com/w/c/numeric/math/tanh
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("tanh(1) = %f\ntanh(-1) = %f\n", tanh(1), tanh(-1));
    printf("tanh(0.1)*sinh(0.2)-cosh(0.2) = %f\n", tanh(0.1) * sinh(0.2) - cosh(0.2));
    // special values
    printf("tanh(+0) = %f\ntanh(-0) = %f\n", tanh(0.0), tanh(-0.0));
}

