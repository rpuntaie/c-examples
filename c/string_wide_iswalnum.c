/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_iswalnum.exe ./c/string_wide_iswalnum.c && (cd ../_build/c/;./string_wide_iswalnum.exe)
https://en.cppreference.com/w/c/string/wide/iswalnum
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t c = L'\u13ad'; // the Cherokee letter HA ('Ꭽ')
    printf("in the default locale, iswalnum(%#x) = %d\n", c, !!iswalnum(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswalnum(%#x) = %d\n", c, !!iswalnum(c));
}

