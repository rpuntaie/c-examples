/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_strndup.exe ./c/string_byte_strndup.c && (cd ../_build/c/;./string_byte_strndup.exe)
https://en.cppreference.com/w/c/string/byte/strndup
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    const size_t n = 3;
    const char *src = "Replica";
    char *dup = strndup(src, n);
    printf("strndup(\"%s\", %lu) == \"%s\"\n", src, n, dup);
    free(dup);
    src = "Hi";
    dup = strndup(src, n);
    printf("strndup(\"%s\", %lu) == \"%s\"\n", src, n, dup);
    free(dup);
    const char arr[] = {'A','B','C','D'}; // NB: no trailing '\0'
    dup = strndup(arr, n);
    printf("strndup({'A','B','C','D'}, %lu) == \"%s\"\n", n, dup);
    free(dup);
}

