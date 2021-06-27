/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_wcslen.exe ./c/string_wide_wcslen.c && (cd ../_build/c/;./string_wide_wcslen.exe)
https://en.cppreference.com/w/c/string/wide/wcslen
*/
#include <wchar.h>
#include <stdio.h>
int main(void)
{
    wchar_t str[] = L"How many wide characters does this string contain?";
    printf("without null character: %zu\n", wcslen(str));
    printf("with null character: %zu\n", sizeof str / sizeof *str);
}

