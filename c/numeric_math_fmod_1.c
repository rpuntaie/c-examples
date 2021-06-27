/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_fmod_1.exe ./c/numeric_math_fmod_1.c && (cd ../_build/c/;./numeric_math_fmod_1.exe)
https://en.cppreference.com/w/c/numeric/math/fmod
*/
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
int main(void)
{
    printf("fmod(+5.1, +3.0) = %.1f\n", fmod(5.1,3));
    printf("fmod(-5.1, +3.0) = %.1f\n", fmod(-5.1,3));
    printf("fmod(+5.1, -3.0) = %.1f\n", fmod(5.1,-3));
    printf("fmod(-5.1, -3.0) = %.1f\n", fmod(-5.1,-3));
    // special values
    printf("fmod(+0.0, 1.0) = %.1f\n", fmod(0, 1));
    printf("fmod(-0.0, 1.0) = %.1f\n", fmod(-0.0, 1));
    printf("fmod(+5.1, Inf) = %.1f\n", fmod(5.1, INFINITY));
    // error handling
    feclearexcept(FE_ALL_EXCEPT);
    printf("fmod(+5.1, 0) = %.1f\n", fmod(5.1, 0));
    if(fetestexcept(FE_INVALID)) puts("    FE_INVALID raised");
}

