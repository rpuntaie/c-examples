/*
gcc -std=c99 -pthread -o ../_build/c/io_putchar.exe ./c/io_putchar.c && (cd ../_build/c/;./io_putchar.exe)
https://en.cppreference.com/w/c/io/putchar
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int ret_code = 0;
    for (char c = 'a'; (ret_code != EOF) && (c != 'z'); c++)
        ret_code = putchar(c);
    /* Test whether EOF was reached. */
    if (ret_code == EOF)
       if (ferror(stdout)) 
       {
          fprintf(stderr,"putchar() failed in file %s at line # %d\n", __FILE__,__LINE__-6);
          perror("putchar()");
          exit(EXIT_FAILURE);
       }
    putchar('\n');
    // putchar return value is not equal to the argument
    int r = 0x1070;
    printf("\n0x%x\n", r);
    r = putchar(r);
    printf("\n0x%x\n", r);
}

