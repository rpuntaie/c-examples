/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/locale_LC_categories.exe ./c/locale_LC_categories.c && (cd ../_build/c/;./locale_LC_categories.exe)
https://en.cppreference.com/w/c/locale/LC_categories
*/
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>
int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8"); // the C locale will be the UTF-8 enabled English
    setlocale(LC_NUMERIC, "de_DE.utf8");   // decimal dot will be German
    setlocale(LC_TIME, "ja_JP.utf8");      // date/time formatting will be Japanese
    wchar_t str[100];
    time_t t = time(NULL);
    wcsftime(str, 100, L"%A %c", localtime(&t));
    wprintf(L"Number: %.2f\nDate: %Ls\n", 3.14, str);
}

