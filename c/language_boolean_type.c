/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_boolean_type.exe ./c/language_boolean_type.c && (cd ../_build/c/;./language_boolean_type.exe)
https://en.cppreference.com/w/c/language/boolean_type
*/
#include <stdio.h>
int main(void)
{
    _Bool a = 0.0;
    _Bool b = 8;
    _Bool c = 0.0/0.0;
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    return 0;
}

