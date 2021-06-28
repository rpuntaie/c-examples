/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_complex_Complex_I.exe ./c/numeric_complex_Complex_I.c && (cd ../_build/c/;./numeric_complex_Complex_I.exe)
https://en.cppreference.com/w/c/numeric/complex/Complex_I
*/
#include <stdio.h>
#include <complex.h>
#undef I
#define J _Complex_I // can be used to redefine I
int main(void)
{
    // can be used to construct a complex number
    double complex z = 1.0 + 2.0 * _Complex_I;
    printf("1.0 + 2.0 * _Complex_I = %.1f%+.1fi\n", creal(z), cimag(z));
    // sign of zero may not be preserved
    double complex z2 = 0.0 + -0.0 * _Complex_I;
    printf("0.0 + -0.0 * _Complex_I = %.1f%+.1fi\n", creal(z2), cimag(z2));
}

