/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_acosh.exe ./c/numeric_math_acosh.c && (cd ../_build/c/;./numeric_math_acosh.exe)
https://en.cppreference.com/w/c/numeric/math/acosh
*/
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
int main(void)
{
    printf("acosh(1) = %f\nacosh(10) = %f\n", acosh(1), acosh(10));
    printf("acosh(DBL_MAX) = %f\nacosh(Inf) = %f\n", acosh(DBL_MAX), acosh(INFINITY));
    //error handling
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("acosh(0.5) = %f\n", acosh(0.5));
    if(errno == EDOM)         perror("    errno == EDOM");
    if(fetestexcept(FE_INVALID)) puts("    FE_INVALID raised");
}

