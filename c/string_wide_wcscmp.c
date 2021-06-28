/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_wcscmp.exe ./c/string_wide_wcscmp.c && (cd ../_build/c/;./string_wide_wcscmp.exe)
https://en.cppreference.com/w/c/string/wide/wcscmp
*/
#include <wchar.h>
#include <stdio.h>
#include <locale.h>
void demo(const wchar_t* lhs, const wchar_t* rhs)
{
    int rc = wcscmp(lhs, rhs);
    const char *rel = rc < 0 ? "precedes" : rc > 0 ? "follows" : "equals";
    setlocale(LC_ALL, "en_US.utf8");
    printf("[%ls] %s [%ls]\n", lhs, rel, rhs);
}
int main(void)
{
    const wchar_t* string = L"どうもありがとうございます";
    demo(string, L"どうも");
    demo(string, L"助かった");
    demo(string + 9, L"ありがとうございます" + 6);
}

