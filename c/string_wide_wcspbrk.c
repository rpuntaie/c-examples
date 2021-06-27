/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_wcspbrk.exe ./c/string_wide_wcspbrk.c && (cd ../_build/c/;./string_wide_wcspbrk.exe)
https://en.cppreference.com/w/c/string/wide/wcspbrk
*/
#include <stdio.h>
#include <wchar.h>
int main(void)
{
    const wchar_t* str = L"Hello world, friend of mine!";
    const wchar_t* sep = L" ,!";
    unsigned int cnt = 0;
    do {
       str = wcspbrk(str, sep); // find separator
       if (str) str += wcsspn(str, sep); // skip separator
       ++cnt; // increment word count
    } while (str && *str);
    wprintf(L"There are %u words.\n", cnt);
}

