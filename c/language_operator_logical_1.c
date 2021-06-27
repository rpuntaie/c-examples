/*
gcc -std=c99 -pthread -o ../_build/c/language_operator_logical_1.exe ./c/language_operator_logical_1.c && (cd ../_build/c/;./language_operator_logical_1.exe)
https://en.cppreference.com/w/c/language/operator_logical
*/
#include <stdbool.h>
#include <stdio.h>
int main(void)
{
    bool b = 2+2==4 && 2*2==4; // b == true
    1 > 2 && puts("this won't print");
    char *p = "abc";
    if(p && *p) // common C idiom: if p is not null
                // AND if p does not point at the end of the string
    {           // (note that thanks to short-circuit evaluation, this
                //  will not attempt to dereference a null pointer)
    // ...      // ... then do some string processing
    }
}

