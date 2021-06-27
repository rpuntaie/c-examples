/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_tolower.exe ./c/string_byte_tolower.c && (cd ../_build/c/;./string_byte_tolower.exe)
https://en.cppreference.com/w/c/string/byte/tolower
*/
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <limits.h>
int main(void)
{
    /* In the default locale: */
    unsigned char l;
    for (unsigned char u=0; u<UCHAR_MAX; u++) {
        l = tolower(u);
        if (l!=u) printf("%c%c ", u,l);
    }
    printf("\n\n");
    unsigned char c = '\xb4'; // the character Ž in ISO-8859-15
                              // but ´ (acute accent) in ISO-8859-1 
    unsigned char c2 = c;   // for printing
    setlocale(LC_ALL, "en_US.iso88591");
    printf("in iso8859-1, tolower('0x%x') gives 0x%x\n", c2, tolower(c));
    setlocale(LC_ALL, "en_US.iso885915");
    printf("in iso8859-15, tolower('0x%x') gives 0x%x\n", c2, tolower(c));
}

