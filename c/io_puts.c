/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_puts.exe ./c/io_puts.c && (cd ../_build/c/;./io_puts.exe)
https://en.cppreference.com/w/c/io/puts
*/
#include <stdio.h>
int main(void)
{
    int rc = puts("Hello World");
    if (rc == EOF)
       perror("puts()"); // POSIX requires that errno is set
}

