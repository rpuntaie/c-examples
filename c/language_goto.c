/*
gcc -std=c99 -pthread -o ../_build/c/language_goto.exe ./c/language_goto.c && (cd ../_build/c/;./language_goto.exe)
https://en.cppreference.com/w/c/language/goto
*/
#include <stdio.h>
int main(void)
{
    // goto can be used to leave a multi-level loop easily
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            printf("(%d;%d)\n",x,y);
            if (x + y >= 3) goto endloop;
        }
    }
endloop:;
}

