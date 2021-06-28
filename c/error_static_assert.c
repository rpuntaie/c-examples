/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/error_static_assert.exe ./c/error_static_assert.c && (cd ../_build/c/;./error_static_assert.exe) || true
https://en.cppreference.com/w/c/error/static_assert
*/
#include <assert.h>
int main(void)
{
    static_assert(2 + 2 == 4, "2+2 isn't 4");      // well-formed
    static_assert(sizeof(int) < sizeof(char),
                 "this program requires that int is less than char"); // compile-time error
}

