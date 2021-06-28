/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_strdup.exe ./c/string_byte_strdup.c #C23 && (cd ../_build/c/;./string_byte_strdup.exe)
https://en.cppreference.com/w/c/string/byte/strdup
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    const char *s1 = "Duplicate me!";
    char *s2 = strdup(s1);
    printf("s2 = \"%s\"\n", s2);
    free(s2);
}

