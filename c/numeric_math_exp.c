/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_exp.exe ./c/numeric_math_exp.c && (cd ../_build/c/;./numeric_math_exp.exe)
https://en.cppreference.com/w/c/numeric/math/exp
*/
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
int main(void)
{
    printf("exp(1) = %f\n", exp(1));
    printf("FV of $100, continuously compounded at 3%% for 1 year = %f\n",
            100*exp(0.03));
    // special values
    printf("exp(-0) = %f\n", exp(-0.0));
    printf("exp(-Inf) = %f\n", exp(-INFINITY));
    //error handling
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("exp(710) = %f\n", exp(710));
    if(errno == ERANGE) perror("    errno == ERANGE");
    if(fetestexcept(FE_OVERFLOW)) puts("    FE_OVERFLOW raised");
}

