/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_wcsncpy.exe ./c/string_wide_wcsncpy.c && (cd ../_build/c/;./string_wide_wcsncpy.exe)
https://en.cppreference.com/w/c/string/wide/wcsncpy
*/
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
int main(void)
{
    wchar_t src[] = L"わゐ";
    wchar_t dest[6] = {L'あ', L'い', L'う', L'え', L'お'};
    wcsncpy(dest, src, 4); // this will copy わゐ and repeat L'\0' two times
    puts("The contents of dest are: ");
    setlocale(LC_ALL, "en_US.utf8");
    for(wchar_t* p = dest; p-dest < sizeof dest / sizeof *dest; ++p) {
        if(*p)
            printf("%lc ", *p);
        else
            printf("\\0 ");
    }
}

