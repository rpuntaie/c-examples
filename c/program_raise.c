/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_raise.exe ./c/program_raise.c && (cd ../_build/c/;./program_raise.exe)
https://en.cppreference.com/w/c/program/raise
*/
#include <signal.h>
#include <stdio.h>
void signal_handler(int signal)
{
    printf("Received signal %d\n", signal);
}
int main(void)
{
    // Install a signal handler.
    signal(SIGTERM, signal_handler);
    printf("Sending signal %d\n", SIGTERM);
    raise(SIGTERM);
    printf("Exit main()\n");
}

