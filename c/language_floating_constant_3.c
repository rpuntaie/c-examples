/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_floating_constant_3.exe ./c/language_floating_constant_3.c && (cd ../_build/c/;./language_floating_constant_3.exe)
https://en.cppreference.com/w/c/language/floating_constant
*/
#include <stdio.h>
int main(void)
{
    printf("15.0     = %a\n", 15.0);
    printf("0x1.ep+3 = %f\n", 0x1.ep+3);
    // Constants outside the range of type double.
    printf("+2.0e+308 --> %g\n",  2.0e+308);
    printf("+1.0e-324 --> %g\n",  1.0e-324);
    printf("-1.0e-324 --> %g\n", -1.0e-324);
    printf("-2.0e+308 --> %g\n", -2.0e+308);
}

