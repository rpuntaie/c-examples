/*
gcc -std=c99 -pthread -o ../_build/c/program_SIG_strategies.exe ./c/program_SIG_strategies.c && (cd ../_build/c/;./program_SIG_strategies.exe)
https://en.cppreference.com/w/c/program/SIG_strategies
*/
#include <signal.h>
#include <stdio.h>
int main(void)
{
    /* using the default signal handler */
    raise(SIGTERM);
    printf("Exit main()\n");   /* never reached */
}

