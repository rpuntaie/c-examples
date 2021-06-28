/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_struct_initialization_6.exe ./c/language_struct_initialization_6.c && (cd ../_build/c/;./language_struct_initialization_6.exe)
https://en.cppreference.com/w/c/language/struct_initialization
*/
#include <stdio.h>
#include <time.h>
int main(void)
{
    char buff[70];
    // designated initializers simplify the use of structs whose
    // order of members is unspecified
    struct tm my_time = { .tm_year=2012-1900, .tm_mon=9, .tm_mday=9,
                          .tm_hour=8, .tm_min=10, .tm_sec=20 };
    strftime(buff, sizeof buff, "%A %c", &my_time);
    puts(buff);
}

