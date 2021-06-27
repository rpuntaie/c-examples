/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_isxdigit.exe ./c/string_byte_isxdigit.c && (cd ../_build/c/;./string_byte_isxdigit.exe)
https://en.cppreference.com/w/c/string/byte/isxdigit
*/
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
int main(void)
{
    for (int ndx=0; ndx<=UCHAR_MAX; ndx++)
        if (isxdigit(ndx)) printf("%c", ndx);
    printf("\n");
}

