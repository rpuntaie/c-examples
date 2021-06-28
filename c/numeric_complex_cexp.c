/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_complex_cexp.exe ./c/numeric_complex_cexp.c && (cd ../_build/c/;./numeric_complex_cexp.exe)
https://en.cppreference.com/w/c/numeric/complex/cexp
*/
#include <stdio.h>
#include <math.h>
#include <complex.h>
int main(void)
{
    double PI = acos(-1);
    double complex z = cexp(I * PI); // Euler's formula
    printf("exp(i*pi) = %.1f%+.1fi\n", creal(z), cimag(z));
}

