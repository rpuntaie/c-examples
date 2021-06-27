/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_iswlower.exe ./c/string_wide_iswlower.c && (cd ../_build/c/;./string_wide_iswlower.exe)
https://en.cppreference.com/w/c/string/wide/iswlower
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t c = L'\u0444'; // Cyrillic small letter ef ('ф')
    printf("in the default locale, iswlower(%#x) = %d\n", c, !!iswlower(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswlower(%#x) = %d\n", c, !!iswlower(c));
}

