/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_cosh.exe ./c/numeric_math_cosh.c && (cd ../_build/c/;./numeric_math_cosh.exe)
https://en.cppreference.com/w/c/numeric/math/cosh
*/
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
int main(void)
{
    printf("cosh(1) = %f\ncosh(-1)= %f\n", cosh(1), cosh(-1));
    printf("log(sinh(1) + cosh(1))=%f\n", log(sinh(1)+cosh(1)));
    // special values
    printf("cosh(+0) = %f\ncosh(-0) = %f\n", cosh(0.0), cosh(-0.0));
    // error handling 
    errno=0; feclearexcept(FE_ALL_EXCEPT);
    printf("cosh(710.5) = %f\n", cosh(710.5));
    if(errno == ERANGE) perror("    errno == ERANGE");
    if(fetestexcept(FE_OVERFLOW)) puts("    FE_OVERFLOW raised");
}

