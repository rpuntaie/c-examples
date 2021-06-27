/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_acos.exe ./c/numeric_math_acos.c && (cd ../_build/c/;./numeric_math_acos.exe)
https://en.cppreference.com/w/c/numeric/math/acos
*/
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>
#include <string.h>
#pragma STDC FENV_ACCESS ON
int main(void)
{
    printf("acos(-1) = %f\n", acos(-1));
    printf("acos(0.0) = %f 2*acos(0.0) = %f\n", acos(0), 2*acos(0));
    printf("acos(0.5) = %f 3*acos(0.5) = %f\n", acos(0.5), 3*acos(0.5));
    printf("acos(1) = %f\n", acos(1));
    // error handling 
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("acos(1.1) = %f\n", acos(1.1));
    if(errno == EDOM) perror("    errno == EDOM");
    if(fetestexcept(FE_INVALID)) puts("    FE_INVALID raised");
}

