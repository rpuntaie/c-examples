/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/chrono_time_t.exe ./c/chrono_time_t.c && (cd ../_build/c/;./chrono_time_t.exe)
https://en.cppreference.com/w/c/chrono/time_t
*/
#include <stdio.h>
#include <time.h>
#include <stdint.h>
int main(void)
{
    time_t epoch = 0;
    printf("%jd seconds since the epoch began\n", (intmax_t)epoch);
    printf("%s", asctime(gmtime(&epoch)));
}

