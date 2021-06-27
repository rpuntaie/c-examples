/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_iswalpha.exe ./c/string_wide_iswalpha.c && (cd ../_build/c/;./string_wide_iswalpha.exe)
https://en.cppreference.com/w/c/string/wide/iswalpha
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t c = L'\u0b83'; // Tamil sign Visarga ('ஃ')
    printf("in the default locale, iswalpha(%#x) = %d\n", c, !!iswalpha(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswalpha(%#x) = %d\n", c, !!iswalpha(c));
}

