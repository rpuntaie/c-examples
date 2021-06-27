/*
gcc -std=c99 -pthread -o ../_build/c/numeric_complex_cproj.exe ./c/numeric_complex_cproj.c && (cd ../_build/c/;./numeric_complex_cproj.exe)
https://en.cppreference.com/w/c/numeric/complex/cproj
*/
#include <stdio.h>
#include <complex.h>
#include <math.h>
int main(void)
{
    double complex z1 = cproj(1 + 2*I);
    printf("cproj(1+2i) = %.1f%+.1fi\n", creal(z1),cimag(z1));
    double complex z2 = cproj(INFINITY+2.0*I);
    printf("cproj(Inf+2i) = %.1f%+.1fi\n", creal(z2),cimag(z2));
    double complex z3 = cproj(INFINITY-2.0*I);
    printf("cproj(Inf-2i) = %.1f%+.1fi\n", creal(z3),cimag(z3));
}

