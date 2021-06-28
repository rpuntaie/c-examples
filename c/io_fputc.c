/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_fputc.exe ./c/io_fputc.c && (cd ../_build/c/;./io_fputc.exe)
https://en.cppreference.com/w/c/io/fputc
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int ret_code = 0;
    for (char c = 'a'; (ret_code != EOF) && (c != 'z'); c++)
        ret_code = putc(c, stdout);
    /* Test whether EOF was reached. */
    if (ret_code == EOF)
       if (ferror(stdout)) 
       {
          perror("putc()");
          fprintf(stderr,"putc() failed in file %s at line # %d\n", __FILE__,__LINE__-7);
          exit(EXIT_FAILURE);
       }
    putc('\n', stdout);
    return EXIT_SUCCESS;
}

