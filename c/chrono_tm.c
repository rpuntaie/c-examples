/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/chrono_tm.exe ./c/chrono_tm.c && (cd ../_build/c/;./chrono_tm.exe)
https://en.cppreference.com/w/c/chrono/tm
*/
#include <stdio.h>
#include <time.h>
int main(void)
{
    struct tm start = {.tm_mday=1};
    mktime(&start);
    printf("%s", asctime(&start));
}

