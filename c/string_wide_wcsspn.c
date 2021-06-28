/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_wcsspn.exe ./c/string_wide_wcsspn.c && (cd ../_build/c/;./string_wide_wcsspn.exe)
https://en.cppreference.com/w/c/string/wide/wcsspn
*/
#include <locale.h>
#include <wchar.h>
int main(void)
{
    wchar_t dest[] = L"白猫 黑狗 甲虫";
    const wchar_t src[] = L" 狗猫 白黑 ";
    const size_t len = wcsspn(dest, src);
    dest[len] = L'\0'; /* terminates the segment to print it out */
    setlocale(LC_ALL, "en_US.utf8");
    wprintf(L"The length of maximum initial segment is %td.\n"
            L"The segment is \"%ls\".\n", len, dest);
}

