/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_iswgraph.exe ./c/string_wide_iswgraph.c && (cd ../_build/c/;./string_wide_iswgraph.exe)
https://en.cppreference.com/w/c/string/wide/iswgraph
*/
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int main(void)
{
    wchar_t c = L'\u2602'; // the Unicode character Umbrella ('☂')
    printf("in the default locale, iswgraph(%#x) = %d\n", c, !!iswgraph(c));
    setlocale(LC_ALL, "en_US.utf8");
    printf("in Unicode locale, iswgraph(%#x) = %d\n", c, !!iswgraph(c));
}

