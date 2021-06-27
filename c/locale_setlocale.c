/*
gcc -std=c99 -pthread -o ../_build/c/locale_setlocale.exe ./c/locale_setlocale.c && (cd ../_build/c/;./locale_setlocale.exe)
https://en.cppreference.com/w/c/locale/setlocale
*/
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>
int main(void)
{
    // the C locale will be UTF-8 enabled English;
    // decimal dot will be German
    // date and time formatting will be Japanese
    setlocale(LC_ALL, "en_US.UTF-8");
    setlocale(LC_NUMERIC, "de_DE.utf8");
    setlocale(LC_TIME, "ja_JP.utf8");
    wchar_t str[100];
    time_t t = time(NULL);
    wcsftime(str, 100, L"%A %c", localtime(&t));
    wprintf(L"Number: %.2f\nDate: %Ls\n", 3.14, str);
}

