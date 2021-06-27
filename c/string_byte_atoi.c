/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_atoi.exe ./c/string_byte_atoi.c && (cd ../_build/c/;./string_byte_atoi.exe)
https://en.cppreference.com/w/c/string/byte/atoi
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("%i\n", atoi(" -123junk"));
    printf("%i\n", atoi("0"));
    printf("%i\n", atoi("junk"));         // no conversion can be performed
    printf("%i\n", atoi("2147483648"));   // UB: out of range of int
}

