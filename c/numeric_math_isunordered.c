/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_isunordered.exe ./c/numeric_math_isunordered.c && (cd ../_build/c/;./numeric_math_isunordered.exe)
https://en.cppreference.com/w/c/numeric/math/isunordered
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("isunordered(NAN,1.0) = %d\n", isunordered(NAN,1.0));
    printf("isunordered(1.0,NAN) = %d\n", isunordered(1.0,NAN));
    printf("isunordered(NAN,NAN) = %d\n", isunordered(NAN,NAN));
    printf("isunordered(1.0,0.0) = %d\n", isunordered(1.0,0.0));
    return 0;
}

