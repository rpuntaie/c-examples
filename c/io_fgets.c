/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_fgets.exe ./c/io_fgets.c && (cd ../_build/c/;./io_fgets.exe)
https://en.cppreference.com/w/c/io/fgets
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE* tmpf = tmpfile();
    fputs("Alan Turing\n", tmpf);
    fputs("John von Neumann\n", tmpf);
    fputs("Alonzo Church\n", tmpf);
    rewind(tmpf);
    char buf[8];
    while (fgets(buf, sizeof buf, tmpf) != NULL)
          printf("\"%s\"\n", buf);
    if (feof(tmpf))
       puts("End of file reached");
}

