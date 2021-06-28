/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/locale_localeconv.exe ./c/locale_localeconv.c && (cd ../_build/c/;./locale_localeconv.exe)
https://en.cppreference.com/w/c/locale/localeconv
*/
#include <stdio.h>
#include <locale.h>
int main(void)
{
  setlocale(LC_MONETARY, "en_IN.utf8");
  struct lconv *lc = localeconv();
  printf("Local Currency Symbol        : %s\n", lc->currency_symbol);
  printf("International Currency Symbol: %s\n", lc->int_curr_symbol);
}

