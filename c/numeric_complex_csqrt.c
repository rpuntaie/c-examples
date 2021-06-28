/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_complex_csqrt.exe ./c/numeric_complex_csqrt.c && (cd ../_build/c/;./numeric_complex_csqrt.exe)
https://en.cppreference.com/w/c/numeric/complex/csqrt
*/
#include <stdio.h>
#include <complex.h>
int main(void)
{
    double complex z1 = csqrt(-4);
    printf("Square root of -4 is %.1f%+.1fi\n", creal(z1), cimag(z1));
    double complex z2 = csqrt(conj(-4)); // or, in C11, CMPLX(-4, -0.0)
    printf("Square root of -4-0i, the other side of the cut, is "
           "%.1f%+.1fi\n", creal(z2), cimag(z2));
}

