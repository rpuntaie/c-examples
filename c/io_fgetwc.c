/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_fgetwc.exe ./c/io_fgetwc.c && (cd ../_build/c/;./io_fgetwc.exe)
https://en.cppreference.com/w/c/io/fgetwc
*/
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <errno.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    FILE *fp = fopen("fgetwc.dat", "w");
    if(!fp) {
        perror("Can't open file for writing");
        return EXIT_FAILURE;
    }
    fputs("кошка\n", fp);
    fclose(fp);
    fp = fopen("fgetwc.dat", "r");
    if(!fp) {
        perror("Can't open file for reading");
        return EXIT_FAILURE;
    }
    wint_t wc;
    errno = 0;
    while ((wc = fgetwc(fp)) != WEOF)
        putwchar(wc);
    if (ferror(fp)) {
        if (errno == EILSEQ)
            puts("Character encoding error while reading.");
        else
            puts("I/O error when reading");
    } else if (feof(fp))
        puts("End of file reached successfully");
    fclose(fp);
}

