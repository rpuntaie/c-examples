/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_memset.exe ./c/string_byte_memset.c && (cd ../_build/c/;./string_byte_memset.exe)
https://en.cppreference.com/w/c/string/byte/memset
*/
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char str[] = "ghghghghghghghghghghgh";
    puts(str);
    memset(str,'a',5);
    puts(str);
#ifdef __STDC_LIB_EXT1__
    set_constraint_handler_s(ignore_handler_s);
    int r = memset_s(str, sizeof str, 'b', 5);
    printf("str = \"%s\", r = %d\n", str, r);
    r = memset_s(str, 5, 'c', 10);   // count is greater than destsz  
    printf("str = \"%s\", r = %d\n", str, r);
#endif
}

