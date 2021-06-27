/*
gcc -std=c99 -pthread -o ../_build/c/language_inline_2.exe ./c/language_inline_2.c && (cd ../_build/c/;./language_inline_2.exe)
https://en.cppreference.com/w/c/language/inline
*/
// file test.h
#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
inline int sum (int a, int b)
{
    return a+b;
}
#endif
// file sum.c
#include "test.h"
extern inline int sum (int a, int b); // provides external definition
// file test1.c
#include <stdio.h>
#include "test.h"
extern int f(void);
int main(void)
{
    printf("%d\n", sum(1, 2) + f());
}
// file test2.c
#include "test.h"
int f(void)
{
    return sum(2, 3);
}

