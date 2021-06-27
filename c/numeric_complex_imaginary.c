/*
gcc -std=c99 -pthread -o ../_build/c/numeric_complex_imaginary.exe ./c/numeric_complex_imaginary.c && (cd ../_build/c/;./numeric_complex_imaginary.exe)
https://en.cppreference.com/w/c/numeric/complex/imaginary
*/
#include <stdio.h>
#include <complex.h>
int main(void)
{
    double imaginary i = 2.0*I; // pure imaginary
    double f = 1.0; // pure real
    double complex z = f + i; // complex number
    printf("z = %.1f%+.1fi\n", creal(z), cimag(z));
}

