/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_at_quick_exit.exe ./c/program_at_quick_exit.c && (cd ../_build/c/;./program_at_quick_exit.exe)
https://en.cppreference.com/w/c/program/at_quick_exit
*/
#include <stdlib.h>
#include <stdio.h>
void f1(void)
{
    puts("pushed first");
    fflush(stdout);
}
void f2(void)
{
    puts("pushed second");
}
int main(void)
{
    at_quick_exit(f1);
    at_quick_exit(f2);
    quick_exit(0);
}

