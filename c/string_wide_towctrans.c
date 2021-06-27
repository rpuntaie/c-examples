/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_towctrans.exe ./c/string_wide_towctrans.c && (cd ../_build/c/;./string_wide_towctrans.exe)
https://en.cppreference.com/w/c/string/wide/towctrans
*/
#include <locale.h>
#include <wctype.h>
#include <wchar.h>
#include <stdio.h>
int main(void)
{
    setlocale(LC_ALL, "ja_JP.UTF-8");
    wchar_t kana[] = L"ヒラガナ";
    size_t sz = sizeof kana / sizeof *kana;
    wchar_t hira[sz];
    for(size_t n = 0; n < sz; ++n)
        hira[n] = towctrans(kana[n], wctrans("tojhira"));
    printf("katakana characters %ls are %ls in hiragana\n", kana, hira);
}

