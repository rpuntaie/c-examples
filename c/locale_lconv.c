/*
gcc -std=c99 -pthread -o ../_build/c/locale_lconv.exe ./c/locale_lconv.c && (cd ../_build/c/;./locale_lconv.exe)
https://en.cppreference.com/w/c/locale/lconv
*/
#include <locale.h>
#include <stdio.h>
int main(void)
{
    setlocale(LC_ALL, "ja_JP.UTF-8");
    struct lconv *lc = localeconv();
    printf("Japanese currency symbol: %s(%s)\n", lc->currency_symbol, lc->int_curr_symbol);
}

