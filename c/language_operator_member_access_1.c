/*
gcc -std=c99 -pthread -o ../_build/c/language_operator_member_access_1.exe ./c/language_operator_member_access_1.c && (cd ../_build/c/;./language_operator_member_access_1.exe)
https://en.cppreference.com/w/c/language/operator_member_access
*/
#include <stdio.h>
int main(void)
{
    int n = 1;
    int* p = &n;
    printf("*p = %d\n", *p); // the value of *p is what's stored in n
    *p = 7; // *p is lvalue
    printf("*p = %d\n", *p);
}

