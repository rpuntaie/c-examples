/*
gcc -std=c99 -pthread -o ../_build/c/io_freopen.exe ./c/io_freopen.c && (cd ../_build/c/;./io_freopen.exe)
https://en.cppreference.com/w/c/io/freopen
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    puts("stdout is printed to console");
    if (freopen("redir.txt", "w", stdout) == NULL)
    {
       perror("freopen() failed");
       return EXIT_FAILURE;
    }
    puts("stdout is redirected to a file"); // this is written to redir.txt
    fclose(stdout);
}

