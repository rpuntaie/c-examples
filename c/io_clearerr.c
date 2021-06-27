/*
gcc -std=c99 -pthread -o ../_build/c/io_clearerr.exe ./c/io_clearerr.c && (cd ../_build/c/;./io_clearerr.exe)
https://en.cppreference.com/w/c/io/clearerr
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(void)
{
    FILE* tmpf = tmpfile();
    fputs("abcde\n", tmpf);
    rewind(tmpf);
    int ch;
    while ((ch=fgetc(tmpf)) != EOF)
          printf("%c", ch);
    assert(feof(tmpf)); // the loop is expected to terminate by eof
    puts("End of file reached");
    clearerr(tmpf);  // clear eof
    if (feof(tmpf))
        puts("EOF indicator set");
    else
        puts("EOF indicator cleared\n");
}

