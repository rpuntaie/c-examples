/*
gcc -std=c99 -pthread -o ../_build/c/chrono_asctime.exe ./c/chrono_asctime.c && (cd ../_build/c/;./chrono_asctime.exe)
https://en.cppreference.com/w/c/chrono/asctime
*/
#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>
#include <stdio.h>
int main(void)
{
    struct tm tm = *localtime(&(time_t){time(NULL)});
    printf("%s", asctime(&tm));
#ifdef __STDC_LIB_EXT1__
    char str[26];
    asctime_s(str, sizeof str, &tm);
    printf("%s", str);
#endif
}

