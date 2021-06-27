/*
gcc -std=c99 -pthread -o ../_build/c/string_multibyte_wctomb.exe ./c/string_multibyte_wctomb.c && (cd ../_build/c/;./string_multibyte_wctomb.exe)
https://en.cppreference.com/w/c/string/multibyte/wctomb
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void demo(wchar_t wc)
{
    printf("State-dependent encoding?   %d\n", wctomb(NULL, wc));
    char mb[MB_CUR_MAX];
    int len = wctomb(mb,wc);
    printf("wide char '%lc' -> multibyte char '", wc);
    for (int idx = 0; idx < len; ++idx)
        printf("%#2x ", (unsigned char)mb[idx]);
    printf("'\n");
}
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    printf("MB_CUR_MAX = %zu\n", MB_CUR_MAX);
    demo(L'A');
    demo(L'\u00df');
    demo(L'\U0001d10b');
}

