/*
gcc -std=c99 -pthread -o ../_build/c/io_tmpnam.exe ./c/io_tmpnam.c && (cd ../_build/c/;./io_tmpnam.exe)
https://en.cppreference.com/w/c/io/tmpnam
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    char* name1 = tmpnam(NULL);
    printf("temporary file name: %s\n", name1);
    char name2[L_tmpnam];
    if (tmpnam(name2))
        printf("temporary file name: %s\n", name2);
}

