/*
gcc -std=c99 -pthread -o ../_build/c/io_getchar.exe ./c/io_getchar.c && (cd ../_build/c/;./io_getchar.exe)
https://en.cppreference.com/w/c/io/getchar
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{ 
    int ch;
    while ((ch=getchar()) != EOF)   /* read/print "abcde" from stdin */
          printf("%c", ch);
    /* Test reason for reaching EOF. */
    if (feof(stdin))          /* if failure caused by end-of-file condition */
       puts("End of file reached");
    else if (ferror(stdin))   /* if failure caused by some other error      */
         {
            perror("getchar()");
            fprintf(stderr,"getchar() failed in file %s at line # %d\n", __FILE__,__LINE__-9);
            exit(EXIT_FAILURE);
         }
    return EXIT_SUCCESS;
}

