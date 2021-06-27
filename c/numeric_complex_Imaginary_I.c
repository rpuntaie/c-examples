/*
gcc -std=c99 -pthread -o ../_build/c/numeric_complex_Imaginary_I.exe ./c/numeric_complex_Imaginary_I.c && (cd ../_build/c/;./numeric_complex_Imaginary_I.exe)
https://en.cppreference.com/w/c/numeric/complex/Imaginary_I
*/
#include <stdio.h>
#include <complex.h>
#include <math.h>
int main(void)
{
    double complex z1 = 0.0 + INFINITY * _Imaginary_I;
    printf("z1 = %.1f%+.1fi\n", creal(z1), cimag(z1));
    double complex z2 = 0.0 + INFINITY * _Complex_I;
    printf("z2 = %.1f%+.1fi\n", creal(z2), cimag(z2));
}

