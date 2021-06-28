/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_iswupper.exe ./c/string_wide_iswupper.c && (cd ../_build/c/;./string_wide_iswupper.exe)
https://en.cppreference.com/w/c/string/wide/iswupper
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t c = L'\u053d'; // Armenian capital letter xeh ('Խ')
    printf("in the default locale, iswupper(%#x) = %d\n", c, !!iswupper(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswupper(%#x) = %d\n", c, !!iswupper(c));
}

