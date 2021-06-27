/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_wcstol.exe ./c/string_wide_wcstol.c && (cd ../_build/c/;./string_wide_wcstol.exe)
https://en.cppreference.com/w/c/string/wide/wcstol
*/
#include <stdio.h>
#include <errno.h>
#include <wchar.h>
int main(void)
{
    const wchar_t *p = L"10 200000000000000000000000000000 30 -40";
    printf("Parsing L'%ls':\n", p);
    wchar_t *end;
    for (long i = wcstol(p, &end, 10);
         p != end;
         i = wcstol(p, &end, 10))
    {
        printf("'%.*ls' -> ", (int)(end-p), p);
        p = end;
        if (errno == ERANGE){
            printf("range error, got ");
            errno = 0;
        }
        printf("%ld\n", i);
    }
}

