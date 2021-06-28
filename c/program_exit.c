/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_exit.exe ./c/program_exit.c && (cd ../_build/c/;./program_exit.exe) || true
https://en.cppreference.com/w/c/program/exit
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp = fopen("data.txt","r");
    if (fp == NULL) {
       fprintf(stderr, "error opening file data.txt in function main()\n");
       exit( EXIT_FAILURE );
    }
    fclose(fp);
    printf("Normal Return\n");
    return EXIT_SUCCESS ;
}

