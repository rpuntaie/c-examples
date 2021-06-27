/*
gcc -std=c99 -pthread -o ../_build/c/error_assert.exe ./c/error_assert.c && (cd ../_build/c/;./error_assert.exe)
https://en.cppreference.com/w/c/error/assert
*/
#include <stdio.h>
// uncomment to disable assert()
// #define NDEBUG
#include <assert.h>
#include <math.h>
int main(void)
{
    double x = -1.0;
    assert(x >= 0.0);
    printf("sqrt(x) = %f\n", sqrt(x));   
    return 0;
}

