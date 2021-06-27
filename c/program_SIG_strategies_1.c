/*
gcc -std=c99 -pthread -o ../_build/c/program_SIG_strategies_1.exe ./c/program_SIG_strategies_1.c && (cd ../_build/c/;./program_SIG_strategies_1.exe)
https://en.cppreference.com/w/c/program/SIG_strategies
*/
#include <signal.h>
#include <stdio.h>
int main(void)
{
    /* ignoring the signal */
    signal(SIGTERM, SIG_IGN);
    raise(SIGTERM);
    printf("Exit main()\n");
}

