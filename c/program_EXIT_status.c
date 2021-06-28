/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_EXIT_status.exe ./c/program_EXIT_status.c && (cd ../_build/c/;./program_EXIT_status.exe) || true
https://en.cppreference.com/w/c/program/EXIT_status
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp = fopen("data.txt","r");
    if (fp == NULL)
    {
       fprintf(stderr,"fopen() failed in file %s at line # %d", __FILE__,__LINE__);
       exit(EXIT_FAILURE);
    }
    /* Normal processing continues here. */
    fclose(fp);
    printf("Normal Return\n");
    return EXIT_SUCCESS;
}

