/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_iswcntrl.exe ./c/string_wide_iswcntrl.c && (cd ../_build/c/;./string_wide_iswcntrl.exe)
https://en.cppreference.com/w/c/string/wide/iswcntrl
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t c = L'\u2028'; // the Unicode character "line separator"
    printf("in the default locale, iswcntrl(%#x) = %d\n", c, !!iswcntrl(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswcntrl(%#x) = %d\n", c, !!iswcntrl(c));
}

