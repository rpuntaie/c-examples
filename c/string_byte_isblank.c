/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_isblank.exe ./c/string_byte_isblank.c && (cd ../_build/c/;./string_byte_isblank.exe)
https://en.cppreference.com/w/c/string/byte/isblank
*/
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
int main(void)
{
    for (int ndx=0; ndx<=UCHAR_MAX; ndx++)
        if (isblank(ndx)) printf("0x%02x\n", ndx);
}

