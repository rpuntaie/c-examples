/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_towlower.exe ./c/string_wide_towlower.c && (cd ../_build/c/;./string_wide_towlower.exe)
https://en.cppreference.com/w/c/string/wide/towlower
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t wc = L'\u0190'; // Latin capital open E ('Ɛ')
    printf("in the default locale, towlower(%#x) = %#x\n", wc, towlower(wc));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, towlower(%#x) = %#x\n", wc, towlower(wc));
}

