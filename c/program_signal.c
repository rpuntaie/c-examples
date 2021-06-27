/*
gcc -std=c99 -pthread -o ../_build/c/program_signal.exe ./c/program_signal.c && (cd ../_build/c/;./program_signal.exe)
https://en.cppreference.com/w/c/program/signal
*/
#include <signal.h>
#include <stdio.h>
volatile sig_atomic_t gSignalStatus;
void signal_handler(int signal)
{
  gSignalStatus = signal;
}
int main(void)
{
  signal(SIGINT, signal_handler);
  printf("SignalValue: %d\n", gSignalStatus);
  printf("Sending signal: %d\n", SIGINT);
  raise(SIGINT);
  printf("SignalValue: %d\n", gSignalStatus);
}

