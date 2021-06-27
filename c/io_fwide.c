/*
gcc -std=c99 -pthread -o ../_build/c/io_fwide.exe ./c/io_fwide.c && (cd ../_build/c/;./io_fwide.exe)
https://en.cppreference.com/w/c/io/fwide
*/
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
void try_read(FILE* fp)
{
    int c = fgetc(fp);
    if(c == EOF) puts("narrow character read failed");
    else printf("narrow character read '%c'\n", c);
    wint_t wc = fgetwc(fp);
    if(wc == WEOF) puts("wide character read failed");
    else printf("wide character read '%lc'\n", wc);
}
void show(int n)
{
    if(n == 0) puts("no orientation");
    else if (n < 0) puts("narrow orientation");
    else puts("wide orientation");
}
int main(void)
{
    FILE* fp = fopen("main.cpp","r");
    if (!fp) {
        perror("fopen() failed");
        return EXIT_FAILURE;
    }
    // A newly opened stream has no orientation.
    show(fwide(fp, 0));
    // Establish byte orientation.
    show(fwide(fp, -1));
    try_read(fp);
    // Only freopen() can reset stream orientation.
    if (freopen("main.cpp","r",fp) == NULL)
    {
       perror("freopen() failed");
       return EXIT_FAILURE;
    }
    // A reopened stream has no orientation.
    show(fwide(fp, 0));
    // Establish wide orientation.
    show(fwide(fp, 1));
    try_read(fp);
    fclose(fp);
}

