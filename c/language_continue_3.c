/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_continue_3.exe ./c/language_continue_3.c && (cd ../_build/c/;./language_continue_3.exe)
https://en.cppreference.com/w/c/language/continue
*/
#include <stdio.h>
int main(void) 
{
    for (int i = 0; i < 10; i++) {
        if (i != 5) continue;
        printf("%d ", i);             // this statement is skipped each time i != 5
    }
    printf("\n");
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 5; k++) { // only this loop is affected by continue
            if (k == 3) continue;
            printf("%d%d ", j, k);    // this statement is skipped each time k == 3
        }
    }
}

