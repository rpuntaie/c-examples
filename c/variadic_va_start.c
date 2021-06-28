/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/variadic_va_start.exe ./c/variadic_va_start.c && (cd ../_build/c/;./variadic_va_start.exe)
https://en.cppreference.com/w/c/variadic/va_start
*/
#include <stdio.h>
#include <stdarg.h>
int add_nums(int count, ...) 
{
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}
int main(void) 
{
    printf("%d\n", add_nums(4, 25, 25, 50, 50));
}

