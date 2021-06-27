/*
gcc -std=c99 -pthread -o ../_build/c/error_abort_handler_s.exe ./c/error_abort_handler_s.c && (cd ../_build/c/;./error_abort_handler_s.exe)
https://en.cppreference.com/w/c/error/abort_handler_s
*/
#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
#ifdef __STDC_LIB_EXT1__
    char dst[2];
    set_constraint_handler_s(ignore_handler_s);
    int r = strcpy_s(dst, sizeof dst, "Too long!");
    printf("dst = \"%s\", r = %d\n", dst, r);
    set_constraint_handler_s(abort_handler_s);
    r = strcpy_s(dst, sizeof dst, "Too long!");
    printf("dst = \"%s\", r = %d\n", dst, r);
#endif
}

