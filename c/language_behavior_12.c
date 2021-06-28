/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_behavior_12.exe ./c/language_behavior_12.c && (cd ../_build/c/;./language_behavior_12.exe)
https://en.cppreference.com/w/c/language/behavior
*/
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *p = (int*)malloc(sizeof(int));
    int *q = (int*)realloc(p, sizeof(int));
    *p = 1; // UB access to a pointer that was passed to realloc
    *q = 2;
    if (p == q) // UB access to a pointer that was passed to realloc
        printf("%d%d\n", *p, *q);
}

