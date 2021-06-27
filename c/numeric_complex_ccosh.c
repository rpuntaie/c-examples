/*
gcc -std=c99 -pthread -o ../_build/c/numeric_complex_ccosh.exe ./c/numeric_complex_ccosh.c && (cd ../_build/c/;./numeric_complex_ccosh.exe)
https://en.cppreference.com/w/c/numeric/complex/ccosh
*/
#include <stdio.h>
#include <math.h>
#include <complex.h>
int main(void)
{
    double complex z = ccosh(1);  // behaves like real cosh along the real line
    printf("cosh(1+0i) = %f%+fi (cosh(1)=%f)\n", creal(z), cimag(z), cosh(1));
    double complex z2 = ccosh(I); // behaves like real cosine along the imaginary line
    printf("cosh(0+1i) = %f%+fi ( cos(1)=%f)\n", creal(z2), cimag(z2), cos(1));
}

