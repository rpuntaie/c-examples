/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_isspace.exe ./c/string_byte_isspace.c && (cd ../_build/c/;./string_byte_isspace.exe)
https://en.cppreference.com/w/c/string/byte/isspace
*/
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
int main(void)
{
    for (int ndx=0; ndx<=UCHAR_MAX; ndx++)
        if (isspace(ndx)) printf("0x%02x\n", ndx);
}

