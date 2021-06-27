/*
gcc -std=c99 -pthread -o ../_build/c/string_multibyte_mbstowcs.exe ./c/string_multibyte_mbstowcs.c && (cd ../_build/c/;./string_multibyte_mbstowcs.exe)
https://en.cppreference.com/w/c/string/multibyte/mbstowcs
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    const char* mbstr = u8"z\u00df\u6c34\U0001F34C"; // or u8"zß水🍌"
    wchar_t wstr[5];
    mbstowcs(wstr, mbstr, 5);
    wprintf(L"MB string: %s\n", mbstr);
    wprintf(L"Wide string: %ls\n", wstr);
}

