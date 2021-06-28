/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_setjmp_4.exe ./c/program_setjmp_4.c && (cd ../_build/c/;./program_setjmp_4.exe)
https://en.cppreference.com/w/c/program/setjmp
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
    volatile int count = 0; // modified local vars in setjmp scope must be volatile
    if (setjmp(jump_buffer) != 9) // compare against constant in an if
        a(++count);
}

