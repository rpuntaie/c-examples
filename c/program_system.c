/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_system.exe ./c/program_system.c && (cd ../_build/c/;./program_system.exe)
https://en.cppreference.com/w/c/program/system
*/
#include <stdlib.h>
int main(void) {
    system("date +%A");
}

