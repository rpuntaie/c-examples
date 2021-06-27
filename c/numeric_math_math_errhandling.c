/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_math_errhandling.exe ./c/numeric_math_math_errhandling.c && (cd ../_build/c/;./numeric_math_math_errhandling.exe)
https://en.cppreference.com/w/c/numeric/math/math_errhandling
*/
#include <stdio.h>
#include <fenv.h>
#include <math.h>
#include <errno.h>
#pragma STDC FENV_ACCESS ON
int main(void)
{
    printf("MATH_ERRNO is %s\n", math_errhandling & MATH_ERRNO ? "set" : "not set");
    printf("MATH_ERREXCEPT is %s\n",
           math_errhandling & MATH_ERREXCEPT ? "set" : "not set");
    feclearexcept(FE_ALL_EXCEPT);
    errno = 0;
    printf("log(0) = %f\n", log(0));
    if(errno == ERANGE)
        perror("errno == ERANGE");
    if(fetestexcept(FE_DIVBYZERO))
        puts("FE_DIVBYZERO (pole error) reported");
}

