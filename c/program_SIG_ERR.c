/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_SIG_ERR.exe ./c/program_SIG_ERR.c && (cd ../_build/c/;./program_SIG_ERR.exe)
https://en.cppreference.com/w/c/program/SIG_ERR
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void signal_handler(int signal)
{
    printf("Received signal %d\n", signal);
}
int main(void)
{
    /* Install a signal handler. */
    if (signal(SIGTERM, signal_handler) == SIG_ERR)
    {
        printf("Error while installing a signal handler.\n");
        exit(EXIT_FAILURE);
    }
    printf("Sending signal %d\n", SIGTERM);
    if (raise(SIGTERM) != 0)
    {
        printf("Error while raising the SIGTERM signal.\n");
        exit(EXIT_FAILURE);
    }
    printf("Exit main()\n");
    return EXIT_SUCCESS;
}

