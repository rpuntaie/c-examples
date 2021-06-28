/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/numeric_math_div_8.exe ./c/numeric_math_div_8.c && (cd ../_build/c/;./numeric_math_div_8.exe)
https://en.cppreference.com/w/c/numeric/math/div
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// demo only: does not check for buffer overflow
void itoa(int n, int base, char* buf)
{
    div_t dv = {.quot = n};
    char* p = buf;
    do {
        dv = div(dv.quot, base);
        *p++ = "0123456789abcdef"[abs(dv.rem)];
    } while(dv.quot);
    if(n<0) *p++ = '-';
    *p-- = '\0';
    while(buf < p) { char c = *p; *p-- = *buf; *buf++ = c; } // reverse
}
int main(void)
{
    char buf[100];
    itoa(12346, 10, buf);
    printf("%s\n", buf);
    itoa(-12346, 10, buf);
    printf("%s\n", buf);
    itoa(65535, 16, buf);
    printf("%s\n", buf);
}

