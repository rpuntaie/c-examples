/*
gcc -std=c99 -pthread -o ../_build/c/numeric_complex_creal.exe ./c/numeric_complex_creal.c && (cd ../_build/c/;./numeric_complex_creal.exe)
https://en.cppreference.com/w/c/numeric/complex/creal
*/
#include <stdio.h>
#include <complex.h>
int main(void)
{    
    double complex z = 1.0 + 2.0*I;
    printf("%f%+fi\n", creal(z), cimag(z));
}

