/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_erf.exe ./c/numeric_math_erf.c && (cd ../_build/c/;./numeric_math_erf.exe)
https://en.cppreference.com/w/c/numeric/math/erf
*/
#include <stdio.h>
#include <math.h>
double phi(double x1, double x2)
{
    return (erf(x2/sqrt(2)) - erf(x1/sqrt(2)))/2;
}
int main(void)
{
    puts("normal variate probabilities:");
    for(int n=-4; n<4; ++n)
        printf("[%2d:%2d]: %5.2f%%\n", n, n+1, 100*phi(n, n+1));
    puts("special values:");
    printf("erf(-0) = %f\n", erf(-0.0));
    printf("erf(Inf) = %f\n", erf(INFINITY));
}

