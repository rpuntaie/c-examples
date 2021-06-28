/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_fprintf_2.exe ./c/io_fprintf_2.c && (cd ../_build/c/;./io_fprintf_2.exe)
https://en.cppreference.com/w/c/io/fprintf
*/
#include <stdio.h>
int main(void)
{
    const char* s = "Hello";
    printf("Strings - padding:\n");
    printf("\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);
    printf("Strings - truncating:\n");
    printf("\t%.4s\n\t%.*s\n", s, 3, s);
    printf("Characters:\t%c %%\n", 65);
    printf("Integers\n");
    printf("Decimal:\t%i %d %.6i %i %.0i %+i %i\n", 1, 2, 3, 0, 0, 4, -4);
    printf("Hexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
    printf("Octal:\t\t%o %#o %#o\n", 10, 10, 4);
    printf("Floating point\n");
    printf("Rounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
    printf("Padding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
    printf("Scientific:\t%E %e\n", 1.5, 1.5);
    printf("Hexadecimal:\t%a %A\n", 1.5, 1.5);
}

