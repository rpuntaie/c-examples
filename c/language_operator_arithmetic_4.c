/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_operator_arithmetic_4.exe ./c/language_operator_arithmetic_4.c && (cd ../_build/c/;./language_operator_arithmetic_4.exe)
https://en.cppreference.com/w/c/language/operator_arithmetic
*/
#include <stdio.h>
#include <stdint.h>
int main(void)
{
    uint16_t mask = 0x00f0;
    uint32_t a = 0x12345678;
    printf("Value: %#x mask: %#x\n"
           "Setting bits:   %#x\n"
           "Clearing bits:  %#x\n"
           "Selecting bits: %#x\n",
           a,mask,(a|mask),(a&~mask),(a&mask));
}

