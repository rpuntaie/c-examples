/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_memchr.exe ./c/string_byte_memchr.c && (cd ../_build/c/;./string_byte_memchr.exe)
https://en.cppreference.com/w/c/string/byte/memchr
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[] = "ABCDEFG";
    char *ps = memchr(str,'D',strlen(str));
    if (ps != NULL)
       printf ("search character found:  %s\n", ps);
    else
       printf ("search character not found\n");
    return 0;
}

