/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_vfscanf.exe ./c/io_vfscanf.c && (cd ../_build/c/;./io_vfscanf.exe)
https://en.cppreference.com/w/c/io/vfscanf
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
bool checked_sscanf(int count, const char* buf, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int rc = vsscanf(buf, fmt, ap);
    va_end(ap);
    return rc == count;
}
int main(void)
{
    int n, m;
    printf("Parsing '1 2'...");
    if(checked_sscanf(2, "1 2", "%d %d", &n, &m))
        puts("success");
    else
        puts("failure");
    printf("Parsing '1 a'...");
    if(checked_sscanf(2, "1 a", "%d %d", &n, &m))
        puts("success");
    else
        puts("failure");
}

