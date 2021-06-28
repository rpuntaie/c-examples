/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_isgreater.exe ./c/numeric_math_isgreater.c && (cd ../_build/c/;./numeric_math_isgreater.exe)
https://en.cppreference.com/w/c/numeric/math/isgreater
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("isgreater(2.0,1.0)      = %d\n", isgreater(2.0,1.0));
    printf("isgreater(1.0,2.0)      = %d\n", isgreater(1.0,2.0));
    printf("isgreater(INFINITY,1.0) = %d\n", isgreater(INFINITY,1.0));
    printf("isgreater(1.0,NAN)      = %d\n", isgreater(1.0,NAN));
    return 0;
}

