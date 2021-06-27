/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_atof.exe ./c/string_byte_atof.c && (cd ../_build/c/;./string_byte_atof.exe)
https://en.cppreference.com/w/c/string/byte/atof
*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    printf("%g\n", atof("  -0.0000000123junk"));
    printf("%g\n", atof("0.012"));
    printf("%g\n", atof("15e16"));
    printf("%g\n", atof("-0x1afp-2"));
    printf("%g\n", atof("inF"));
    printf("%g\n", atof("Nan"));
    printf("%g\n", atof("1.0e+309"));   // UB: out of range of double
    printf("%g\n", atof("0.0"));
    printf("%g\n", atof("junk"));       // no conversion can be performed
}

