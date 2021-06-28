/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_complex_CMPLX_1.exe ./c/numeric_complex_CMPLX_1.c && (cd ../_build/c/;./numeric_complex_CMPLX_1.exe)
https://en.cppreference.com/w/c/numeric/complex/CMPLX
*/
#include <stdio.h>
#include <complex.h>
int main(void)
{
    double complex z = CMPLX(0.0, -0.0);
    printf("z = %.1f%+.1fi\n", creal(z), cimag(z));
}

