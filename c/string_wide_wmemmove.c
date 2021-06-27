/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_wmemmove.exe ./c/string_wide_wmemmove.c && (cd ../_build/c/;./string_wide_wmemmove.exe)
https://en.cppreference.com/w/c/string/wide/wmemmove
*/
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    wchar_t str[] = L"αβγδεζηθικλμνξοπρστυφχψω";
    printf("%ls\n", str);
    wmemmove(str+4, str+3, 3); // copy from [δεζ] to [εζη]
    printf("%ls\n", str);
}

