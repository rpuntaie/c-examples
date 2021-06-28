/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/thread_thrd_sleep.exe ./c/thread_thrd_sleep.c && (cd ../_build/c/;./thread_thrd_sleep.exe)
https://en.cppreference.com/w/c/thread/thrd_sleep
*/
#include <threads.h>
#include <time.h>
#include <stdio.h>
int main(void)
{
    printf("Time: %s", ctime(&(time_t){time(NULL)}));
    thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); // sleep 1 sec
    printf("Time: %s", ctime(&(time_t){time(NULL)}));
}

