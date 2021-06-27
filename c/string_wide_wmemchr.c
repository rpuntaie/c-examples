/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_wmemchr.exe ./c/string_wide_wmemchr.c && (cd ../_build/c/;./string_wide_wmemchr.exe)
https://en.cppreference.com/w/c/string/wide/wmemchr
*/
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
int main(void)
{
    wchar_t str[] = L"诺不轻信，故人不负我\0诺不轻许，故我不负人。";
    size_t sz = sizeof str / sizeof *str;
    wchar_t target = L'许';
    wchar_t* result = wmemchr(str, target, sz);
    if (result) {
        setlocale(LC_ALL, "en_US.utf8");
        printf("Found '%lc' at position %td\n",target, result - str);
    }
}

