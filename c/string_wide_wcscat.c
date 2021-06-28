/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_wcscat.exe ./c/string_wide_wcscat.c && (cd ../_build/c/;./string_wide_wcscat.exe)
https://en.cppreference.com/w/c/string/wide/wcscat
*/
#include <wchar.h> 
#include <stdio.h>
#include <locale.h>
int main(void) 
{
    wchar_t str[50] = L"Земля, прощай.";
    wcscat(str, L" ");
    wcscat(str, L"В добрый путь.");
    setlocale(LC_ALL, "en_US.utf8");
    printf("%ls", str);
}

