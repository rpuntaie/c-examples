/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_ascii.exe ./c/language_ascii.c && (cd ../_build/c/;./language_ascii.exe)
https://en.cppreference.com/w/c/language/ascii
*/
#include <stdio.h>
int main(void)
{
    puts("Printable ASCII:");
    for (int i = 32; i < 127; ++i) {
        putchar(i);
        putchar(i % 16 == 15 ? '\n' : ' ');
    }
}

