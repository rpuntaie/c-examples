/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_erfc.exe ./c/numeric_math_erfc.c && (cd ../_build/c/;./numeric_math_erfc.exe)
https://en.cppreference.com/w/c/numeric/math/erfc
*/
#include <stdio.h>
#include <math.h>
double normalCDF(double x) // Phi(-∞, x) aka N(x)
{
    return erfc(-x/sqrt(2))/2;
}
int main(void)
{
    puts("normal cumulative distribution function:");
    for(double n=0; n<1; n+=0.1)
        printf("normalCDF(%.2f) %5.2f%%\n", n, 100*normalCDF(n));
    puts("special values:");
    printf("erfc(-Inf) = %f\n", erfc(-INFINITY));
    printf("erfc(Inf) = %f\n", erfc(INFINITY));
}

