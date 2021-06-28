/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_isgreaterequal.exe ./c/numeric_math_isgreaterequal.c && (cd ../_build/c/;./numeric_math_isgreaterequal.exe)
https://en.cppreference.com/w/c/numeric/math/isgreaterequal
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("isgreaterequal(2.0,1.0)      = %d\n", isgreaterequal(2.0,1.0));
    printf("isgreaterequal(1.0,2.0)      = %d\n", isgreaterequal(1.0,2.0));
    printf("isgreaterequal(1.0,1.0)      = %d\n", isgreaterequal(1.0,1.0));
    printf("isgreaterequal(INFINITY,1.0) = %d\n", isgreaterequal(INFINITY,1.0));
    printf("isgreaterequal(1.0,NAN)      = %d\n", isgreaterequal(1.0,NAN));
    return 0;
}

