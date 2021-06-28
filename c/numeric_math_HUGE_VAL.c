/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_HUGE_VAL.exe ./c/numeric_math_HUGE_VAL.c && (cd ../_build/c/;./numeric_math_HUGE_VAL.exe)
https://en.cppreference.com/w/c/numeric/math/HUGE_VAL
*/
#include <math.h>
#include <stdio.h>
int main(void)
{
    double result = 1.0/0.0;
    printf("1.0/0.0 = %f\n", result);
    if (result == HUGE_VAL)
        puts("1.0/0.0 == HUGE_VAL\n");
}

