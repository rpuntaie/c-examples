/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_wide_wcstof.exe ./c/string_wide_wcstof.c && (cd ../_build/c/;./string_wide_wcstof.exe)
https://en.cppreference.com/w/c/string/wide/wcstof
*/
#include <stdio.h>
#include <errno.h>
#include <wchar.h>
int main(void)
{
    const wchar_t *p = L"111.11 -2.22 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
    printf("Parsing L\"%ls\":\n", p);
    wchar_t *end;
    for (double f = wcstod(p, &end); p != end; f = wcstod(p, &end))
    {
        printf("'%.*ls' -> ", (int)(end-p), p);
        p = end;
        if (errno == ERANGE){
            printf("range error, got ");
            errno = 0;
        }
        printf("%f\n", f);
    }
}

