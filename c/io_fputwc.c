/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_fputwc.exe ./c/io_fputwc.c && (cd ../_build/c/;./io_fputwc.exe)
https://en.cppreference.com/w/c/io/fputwc
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <errno.h>
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    errno = 0;
    if (fputwc(L'🍌', stdout) == WEOF) {
        if (errno == EILSEQ)
            puts("Encoding error in fputwc.");
        else
            puts("I/O error in fputwc.");
        return EXIT_FAILURE;
    }
}

