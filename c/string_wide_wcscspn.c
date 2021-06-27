/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_wcscspn.exe ./c/string_wide_wcscspn.c && (cd ../_build/c/;./string_wide_wcscspn.exe)
https://en.cppreference.com/w/c/string/wide/wcscspn
*/
#include <locale.h>
#include <wchar.h>
int main(void)
{
    wchar_t dest[] = L"白猫 黑狗 甲虫";
    /*                      └───┐   */
    const wchar_t *src = L"甲虫,黑狗";
    const size_t len = wcscspn(dest, src);
    dest[len] = L'\0'; /* terminates the segment to print it out */
    setlocale(LC_ALL, "en_US.utf8");
    wprintf(L"The length of maximum initial segment is %td.\n"
            L"The segment is \"%ls\".\n", len, dest);
}

