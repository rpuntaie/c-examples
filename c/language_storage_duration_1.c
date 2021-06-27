/*
gcc -std=c99 -pthread -o ../_build/c/language_storage_duration_1.exe ./c/language_storage_duration_1.c && (cd ../_build/c/;./language_storage_duration_1.exe)
https://en.cppreference.com/w/c/language/storage_duration
*/
// flib.c
#include "flib.h"
static void local_f(int s) {}  // definition with internal linkage (only used in this file)
static int local_state;        // definition with internal linkage (only used in this file)
int state;                     // definition with external linkage (used by main.c)
void f(void) {local_f(state);} // definition with external linkage (used by main.c)

