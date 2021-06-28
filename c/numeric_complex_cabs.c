/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_complex_cabs.exe ./c/numeric_complex_cabs.c && (cd ../_build/c/;./numeric_complex_cabs.exe)
https://en.cppreference.com/w/c/numeric/complex/cabs
*/
#include <stdio.h>
#include <complex.h>
int main(void)
{
    double complex z = 1.0 + 1.0*I;
    printf("%.1f%+.1fi cartesian is rho=%f theta=%f polar\n",
           creal(z), cimag(z), cabs(z), carg(z));
}

