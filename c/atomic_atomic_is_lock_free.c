/*
gcc -std=c17 -latomic -lc -lm -pthread -o ../_build/c/atomic_atomic_is_lock_free.exe ./c/atomic_atomic_is_lock_free.c
https://en.cppreference.com/w/c/atomic/atomic_is_lock_free
*/
#include <stdio.h>
#include <stdatomic.h>
_Atomic struct A { int a[100]; } a;
_Atomic struct B { int x, y; } b;
int main(void)
{
    printf("_Atomic struct A is lock free? %s\n", 
            atomic_is_lock_free(&a) ? "true" : "false");
    printf("_Atomic struct B is lock free? %s\n", 
            atomic_is_lock_free(&b) ? "true" : "false");
}

