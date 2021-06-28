/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_longjmp.exe ./c/program_longjmp.c && (cd ../_build/c/;./program_longjmp.exe)
https://en.cppreference.com/w/c/program/longjmp
*/
#include <stdio.h>
#include <setjmp.h>
#include <stdnoreturn.h>
jmp_buf jump_buffer;
noreturn void a(int count) 
{
    printf("a(%d) called\n", count);
    longjmp(jump_buffer, count+1); // will return count+1 out of setjmp
}
int main(void)
{
    volatile int count = 0; // local vars must be volatile for setjmp
    if (setjmp(jump_buffer) != 9)
        a(count++);
}

