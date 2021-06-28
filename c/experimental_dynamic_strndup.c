/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/experimental_dynamic_strndup.exe ./c/experimental_dynamic_strndup.c && (cd ../_build/c/;./experimental_dynamic_strndup.exe)
https://en.cppreference.com/w/c/experimental/dynamic/strndup
*/
#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    const char *s1 = "String";
    char *s2 = strndup(s1, 2);
    printf("strndup(\"String\", 2) == %s\n", s2);
    free(s2);
}

