/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_iswpunct.exe ./c/string_wide_iswpunct.c && (cd ../_build/c/;./string_wide_iswpunct.exe)
https://en.cppreference.com/w/c/string/wide/iswpunct
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t c = L'\u2051'; // Two asterisks ('⁑')
    printf("in the default locale, iswpunct(%#x) = %d\n", c, !!iswpunct(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswpunct(%#x) = %d\n", c, !!iswpunct(c));
}

