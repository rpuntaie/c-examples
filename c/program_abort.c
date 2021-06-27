/*
gcc -std=c99 -pthread -o ../_build/c/program_abort.exe ./c/program_abort.c && (cd ../_build/c/;./program_abort.exe)
https://en.cppreference.com/w/c/program/abort
*/
#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
    FILE *fp = fopen("data.txt","r");
    if (fp == NULL) {
       fprintf(stderr, "error opening file data.txt in function main()\n");
       abort();
    }
    /* Normal processing continues here. */
    fclose(fp);
    printf("Normal Return\n");
    return 0;
}

