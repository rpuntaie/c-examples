/*
gcc -std=c99 -pthread -o ../_build/c/io_setbuf_1.exe ./c/io_setbuf_1.c && (cd ../_build/c/;./io_setbuf_1.exe)
https://en.cppreference.com/w/c/io/setbuf
*/
#include <stdio.h>
#include <threads.h>
int main(void)
{
    setbuf(stdout, NULL); // unbuffered stdout
    putchar('a'); // 'a' appears immediately if stdout is unbuffered
    thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); // sleep 1 sec
    putchar('b'); 
}

