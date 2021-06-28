/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_iswspace.exe ./c/string_wide_iswspace.c && (cd ../_build/c/;./string_wide_iswspace.exe)
https://en.cppreference.com/w/c/string/wide/iswspace
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t c = L'\u2003'; // Unicode character 'EM SPACE'
    printf("in the default locale, iswspace(%#x) = %d\n", c, !!iswspace(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswspace(%#x) = %d\n", c, !!iswspace(c));
}

