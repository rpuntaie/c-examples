/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_tan.exe ./c/numeric_math_tan.c && (cd ../_build/c/;./numeric_math_tan.exe)
https://en.cppreference.com/w/c/numeric/math/tan
*/
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
int main(void)
{
    double pi = acos(-1);
    // typical usage
    printf("tan  (pi/4) = %+f\n", tan(  pi/4)); //   45 deg
    printf("tan(3*pi/4) = %+f\n", tan(3*pi/4)); //  135 deg
    printf("tan(5*pi/4) = %+f\n", tan(5*pi/4)); // -135 deg
    printf("tan(7*pi/4) = %+f\n", tan(7*pi/4)); //  -45 deg
    // special values
    printf("tan(+0) = %f\n", tan(0.0));
    printf("tan(-0) = %f\n", tan(-0.0));
    // error handling 
    feclearexcept(FE_ALL_EXCEPT);
    printf("tan(INFINITY) = %f\n", tan(INFINITY));
    if(fetestexcept(FE_INVALID)) puts("    FE_INVALID raised");
}

