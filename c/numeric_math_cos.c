/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_cos.exe ./c/numeric_math_cos.c && (cd ../_build/c/;./numeric_math_cos.exe)
https://en.cppreference.com/w/c/numeric/math/cos
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
    printf("cos(pi/3) = %f\n", cos(pi/3));
    printf("cos(pi/2) = %f\n", cos(pi/2));
    printf("cos(-3*pi/4) = %f\n", cos(-3*pi/4));
    // special values
    printf("cos(+0) = %f\n", cos(0.0));
    printf("cos(-0) = %f\n", cos(-0.0));
    // error handling 
    feclearexcept(FE_ALL_EXCEPT);
    printf("cos(INFINITY) = %f\n", cos(INFINITY));
    if(fetestexcept(FE_INVALID)) puts("    FE_INVALID raised");
}

