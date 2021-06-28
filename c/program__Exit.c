/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program__Exit.exe ./c/program__Exit.c && (cd ../_build/c/;./program__Exit.exe)
https://en.cppreference.com/w/c/program/_Exit
*/
#include <stdlib.h>
#include <stdio.h>
/* _Exit does not call functions registered with atexit. */
void f1(void)
{
    puts("pushed first");
}
void f2(void)
{
    puts("pushed second");
}
int main(void)
{
    printf("Enter main()\n");
    atexit(f1);
    atexit(f2);
    fflush(stdout);   /* _Exit may not flush unwritten buffered data */
    _Exit(0);
}

