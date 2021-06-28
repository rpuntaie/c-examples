/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_fputs.exe ./c/io_fputs.c && (cd ../_build/c/;./io_fputs.exe)
https://en.cppreference.com/w/c/io/fputs
*/
#include <stdio.h>
int main(void)
{
    int rc = fputs("Hello World", stdout);
    if (rc == EOF)
       perror("fputs()"); // POSIX requires that errno is set
}

