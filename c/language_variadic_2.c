/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_variadic_2.exe ./c/language_variadic_2.c && (cd ../_build/c/;./language_variadic_2.exe)
https://en.cppreference.com/w/c/language/variadic
*/
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
void tlog(const char* fmt,...)
{
    char msg[50];
    strftime(msg, sizeof msg, "%T", localtime(&(time_t){time(NULL)}));
    printf("[%s] ", msg);
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}
int main(void)
{
   tlog("logging %d %d %d...\n", 1, 2, 3);
}

