/*
gcc -std=c99 -pthread -o ../_build/c/numeric_complex_carg.exe ./c/numeric_complex_carg.c && (cd ../_build/c/;./numeric_complex_carg.exe)
https://en.cppreference.com/w/c/numeric/complex/carg
*/
#include <stdio.h>
#include <complex.h>
int main(void) 
{
    double complex z1 = 1.0+0.0*I;
    printf("phase angle of %.1f%+.1fi is %f\n", creal(z1), cimag(z1), carg(z1));
    double complex z2 = 0.0+1.0*I;
    printf("phase angle of %.1f%+.1fi is %f\n", creal(z2), cimag(z2), carg(z2));
    double complex z3 = -1.0+0.0*I;
    printf("phase angle of %.1f%+.1fi is %f\n", creal(z3), cimag(z3), carg(z3));
    double complex z4 = conj(z3); // or CMPLX(-1, -0.0)
    printf("phase angle of %.1f%+.1fi (the other side of the cut) is %f\n",
             creal(z4), cimag(z4), carg(z4));
}

