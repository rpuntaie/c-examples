/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/chrono_ctime_1.exe ./c/chrono_ctime_1.c && (cd ../_build/c/;./chrono_ctime_1.exe)
https://en.cppreference.com/w/c/chrono/ctime
*/
#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>
#include <stdio.h>
int main(void)
{
    time_t result = time(NULL);
    printf("%s", ctime(&result));
#ifdef __STDC_LIB_EXT1__
    char str[26];
    ctime_s(str,sizeof str,&result);
    printf("%s", str);
#endif
}

