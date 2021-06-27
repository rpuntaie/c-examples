/*
gcc -std=c99 -pthread -o ../_build/c/program_sig_atomic_t.exe ./c/program_sig_atomic_t.c && (cd ../_build/c/;./program_sig_atomic_t.exe)
https://en.cppreference.com/w/c/program/sig_atomic_t
*/
#include <signal.h>
#include <stdio.h>
volatile sig_atomic_t gSignalStatus = 0;
void signal_handler(int signal)
{
    gSignalStatus = signal;
}
int main(void)
{
    /* Install a signal handler. */
    signal(SIGINT, signal_handler);
    printf("SignalValue:   %d\n", gSignalStatus);
    printf("Sending signal %d\n", SIGINT);
    raise(SIGINT);
    printf("SignalValue:   %d\n", gSignalStatus);
}

