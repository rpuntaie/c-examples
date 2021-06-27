/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_towupper.exe ./c/string_wide_towupper.c && (cd ../_build/c/;./string_wide_towupper.exe)
https://en.cppreference.com/w/c/string/wide/towupper
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t wc =  L'\u017f'; // Latin small letter Long S ('ſ')
    printf("in the default locale, towupper(%#x) = %#x\n", wc, towupper(wc));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, towupper(%#x) = %#x\n", wc, towupper(wc));
}

