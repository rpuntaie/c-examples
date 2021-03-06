/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_atexit.exe ./c/program_atexit.c && (cd ../_build/c/;./program_atexit.exe)
https://en.cppreference.com/w/c/program/atexit
*/
#include <stdlib.h>
#include <stdio.h>
void f1(void)
{
    puts("f1");
}
void f2(void)
{
    puts("f2");
}
int main(void)
{
    if ( ! atexit(f1) && ! atexit(f2) && ! atexit(f2) )
        return EXIT_SUCCESS ;
    // atexit registration failed
    return EXIT_FAILURE ;
}   // <- if registration was successful calls f2, f2, f1

