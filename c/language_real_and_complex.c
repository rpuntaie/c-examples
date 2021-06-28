/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_real_and_complex.exe ./c/language_real_and_complex.c && (cd ../_build/c/;./language_real_and_complex.exe)
https://en.cppreference.com/w/c/language/real_and_complex
*/
#include <stdio.h>
#include <complex.h>
int main(void)
{
    /* a real type to a complex type */
    double d = 1.0;
    double _Complex zd;
    zd = d;
    printf("%.1f%+.1fi\n", creal(zd), cimag(zd));
    /* a complex type to a real type */
    zd = 3.0 + 4.0*I;
    d = zd;
    printf("%.1f\n", d);
    return 0;
}

