/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_iswdigit.exe ./c/string_wide_iswdigit.c && (cd ../_build/c/;./string_wide_iswdigit.exe)
https://en.cppreference.com/w/c/string/wide/iswdigit
*/
#include <stdio.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>
void test(wchar_t a3, wchar_t u3, wchar_t j3)
{
    printf("        '%lc' '%lc' '%lc'\n", a3, u3, j3);
    printf("iswdigit %d    %d   %d\n",
           !!iswdigit(a3), !!iswdigit(u3), !!iswdigit(j3));
    printf("jdigit:  %d    %d   %d\n", !!iswctype(a3, wctype("jdigit")),
          !!iswctype(u3, wctype("jdigit")),
          !!iswctype(j3, wctype("jdigit")));
}
int main(void)
{
    wchar_t a3 = L'3';  // the ASCII digit 3
    wchar_t u3 = L'三'; // the CJK numeral 3
    wchar_t j3 = L'３'; // the fullwidth digit 3
    setlocale(LC_ALL, "en_US.utf8");
    puts("In American locale:");
    test(a3, u3, j3);
    setlocale(LC_ALL, "ja_JP.utf8");
    puts("\nIn Japanese locale:");
    test(a3, u3, j3);
}

