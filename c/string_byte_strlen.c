/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_strlen.exe ./c/string_byte_strlen.c && (cd ../_build/c/;./string_byte_strlen.exe)
https://en.cppreference.com/w/c/string/byte/strlen
*/
#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdio.h>
int main(void)
{
    const char str[] = "How many characters does this string contain?";
    printf("without null character: %zu\n", strlen(str));
    printf("with null character:    %zu\n", sizeof str);
#ifdef __STDC_LIB_EXT1__
    printf("without null character: %zu\n", strnlen_s(str, sizeof str));
#endif
}

