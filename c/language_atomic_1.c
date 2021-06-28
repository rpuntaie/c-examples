/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_atomic_1.exe ./c/language_atomic_1.c && (cd ../_build/c/;./language_atomic_1.exe)
https://en.cppreference.com/w/c/language/atomic
*/
#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>
atomic_int acnt;
int cnt;
int f(void* thr_data)
{
    for(int n = 0; n < 1000; ++n) {
        ++cnt;
        ++acnt;
        // for this example, relaxed memory order is sufficient, e.g.
        // atomic_fetch_add_explicit(&acnt, 1, memory_order_relaxed);
    }
    return 0;
}
int main(void)
{
    thrd_t thr[10];
    for(int n = 0; n < 10; ++n)
        thrd_create(&thr[n], f, NULL);
    for(int n = 0; n < 10; ++n)
        thrd_join(thr[n], NULL);
    printf("The atomic counter is %u\n", acnt);
    printf("The non-atomic counter is %u\n", cnt);
}

