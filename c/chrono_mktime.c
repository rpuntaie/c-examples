/*
gcc -std=c99 -pthread -o ../_build/c/chrono_mktime.exe ./c/chrono_mktime.c && (cd ../_build/c/;./chrono_mktime.exe)
https://en.cppreference.com/w/c/chrono/mktime
*/
#define _POSIX_C_SOURCE 200112L // for setenv on gcc
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void)
{
    setenv("TZ", "/usr/share/zoneinfo/America/New_York", 1); // POSIX-specific
    struct tm tm = *localtime(&(time_t){time(NULL)});
    printf("Today is           %s", asctime(&tm));
    printf("(DST is %s)\n", tm.tm_isdst ? "in effect" : "not in effect");
    tm.tm_mon -= 100;  // tm_mon is now outside its normal range
    mktime(&tm);       // tm_dst is not set to -1; today's DST status is used
    printf("100 months ago was %s", asctime(&tm));
    printf("(DST was %s)\n", tm.tm_isdst ? "in effect" : "not in effect");
}

