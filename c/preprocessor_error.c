/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/preprocessor_error.exe ./c/preprocessor_error.c && (cd ../_build/c/;./preprocessor_error.exe)
https://en.cppreference.com/w/c/preprocessor/error
*/
#if __STDC__ != 1
#  error "Not a standard compliant compiler"
#endif
#include <stdio.h>
int main(void)
{
    printf("The compiler used conforms to the ISO C Standard !!");
}

