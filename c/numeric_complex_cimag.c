/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_complex_cimag.exe ./c/numeric_complex_cimag.c && (cd ../_build/c/;./numeric_complex_cimag.exe)
https://en.cppreference.com/w/c/numeric/complex/cimag
*/
#include <stdio.h>
#include <complex.h>
int main(void)
{    
    double complex z = 1.0 + 2.0*I;
    printf("%f%+fi\n", creal(z), cimag(z));
}

