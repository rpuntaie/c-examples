/*
gcc -std=c99 -pthread -o ../_build/c/numeric_complex_ctan.exe ./c/numeric_complex_ctan.c && (cd ../_build/c/;./numeric_complex_ctan.exe)
https://en.cppreference.com/w/c/numeric/complex/ctan
*/
#include <stdio.h>
#include <math.h>
#include <complex.h>
int main(void)
{
    double complex z = ctan(1);  // behaves like real tangent along the real line
    printf("tan(1+0i) = %f%+fi ( tan(1)=%f)\n", creal(z), cimag(z), tan(1));
    double complex z2 = ctan(I); // behaves like tanh along the imaginary line 
    printf("tan(0+1i) = %f%+fi (tanh(1)=%f)\n", creal(z2), cimag(z2), tanh(1));
}

