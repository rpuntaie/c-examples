/*
gcc -std=c99 -pthread -o ../_build/c/numeric_math_islessgreater.exe ./c/numeric_math_islessgreater.c && (cd ../_build/c/;./numeric_math_islessgreater.exe)
https://en.cppreference.com/w/c/numeric/math/islessgreater
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("islessgreater(2.0,1.0)      = %d\n", islessgreater(2.0,1.0));
    printf("islessgreater(1.0,2.0)      = %d\n", islessgreater(1.0,2.0));
    printf("islessgreater(1.0,1.0)      = %d\n", islessgreater(1.0,1.0));
    printf("islessgreater(INFINITY,1.0) = %d\n", islessgreater(INFINITY,1.0));
    printf("islessgreater(1.0,NAN)      = %d\n", islessgreater(1.0,NAN));
    return 0;
}

