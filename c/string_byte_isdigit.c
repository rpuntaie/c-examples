/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_isdigit.exe ./c/string_byte_isdigit.c && (cd ../_build/c/;./string_byte_isdigit.exe)
https://en.cppreference.com/w/c/string/byte/isdigit
*/
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
int main(void)
{
    for (int ndx=0; ndx<=UCHAR_MAX; ndx++)
        if (isdigit(ndx)) printf("%c", ndx);
    printf("\n");
}

