/*
gcc -std=c99 -pthread -o ../_build/c/language_storage_duration_2.exe ./c/language_storage_duration_2.c && (cd ../_build/c/;./language_storage_duration_2.exe)
https://en.cppreference.com/w/c/language/storage_duration
*/
// main.c 
#include "flib.h"
int main(void)
{
    int x[MAX] = {size}; // uses the constant and the read-only variable
    state = 7;           // modifies state in flib.c
    f();                 // calls f() in flib.c
}

