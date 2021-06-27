/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_iswctype.exe ./c/string_wide_iswctype.c && (cd ../_build/c/;./string_wide_iswctype.exe)
https://en.cppreference.com/w/c/string/wide/iswctype
*/
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
const char* classify(wchar_t wc, const char* cat)
{
    return iswctype(wc, wctype(cat)) ? "true" : "false";
}
int main(void)
{
    setlocale(LC_ALL, "ja_JP.UTF-8");
    puts("The character \u6c34 is...");
    const char* cats[] = {"digit", "alpha", "space", "cntrl", "jkanji"};
    for(int n = 0; n < 5; ++n)
        printf("%s? %s\n", cats[n], classify(L'\u6c34', cats[n]));
}

