/*
gcc -std=c99 -pthread -o ../_build/c/language__Noreturn.exe ./c/language__Noreturn.c && (cd ../_build/c/;./language__Noreturn.exe)
https://en.cppreference.com/w/c/language/_Noreturn
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdnoreturn.h>
// causes undefined behavior if i <= 0
// exits if i > 0
noreturn void stop_now(int i) // or _Noreturn void stop_now(int i)
{
    if (i > 0) exit(i);
}
int main(void)
{
  puts("Preparing to stop...");
  stop_now(2);
  puts("This code is never executed.");
}

