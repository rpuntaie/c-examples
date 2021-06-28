/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_copysign.exe ./c/numeric_math_copysign.c && (cd ../_build/c/;./numeric_math_copysign.exe)
https://en.cppreference.com/w/c/numeric/math/copysign
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    printf("copysign(1.0,+2.0)      = %+.1f\n", copysign(1.0,+2.0));
    printf("copysign(1.0,-2.0)      = %+.1f\n", copysign(1.0,-2.0));
    printf("copysign(INFINITY,-2.0) = %f\n",    copysign(INFINITY,-2.0));
    printf("copysign(NAN,-2.0)      = %f\n",    copysign(NAN,-2.0));
}

