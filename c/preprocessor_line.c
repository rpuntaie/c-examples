/*
gcc -std=c99 -pthread -o ../_build/c/preprocessor_line.exe ./c/preprocessor_line.c && (cd ../_build/c/;./preprocessor_line.exe)
https://en.cppreference.com/w/c/preprocessor/line
*/
#include <assert.h>
#define FNAME "test.c"
int main(void)
{
#line 777 FNAME
        assert(2+2 == 5);
}

