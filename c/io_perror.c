/*
gcc -std=c99 -pthread -o ../_build/c/io_perror.exe ./c/io_perror.c && (cd ../_build/c/;./io_perror.exe)
https://en.cppreference.com/w/c/io/perror
*/
#include <stdio.h>
int main(void)
{
    FILE *f = fopen("non_existent", "r");
    if (f == NULL) {
        perror("fopen() failed");
    } else {
        fclose(f);
    }
}

