/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_toupper.exe ./c/string_byte_toupper.c && (cd ../_build/c/;./string_byte_toupper.exe)
https://en.cppreference.com/w/c/string/byte/toupper
*/
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <limits.h>
int main(void)
{
    /* In the default locale: */
    unsigned char u;
    for (unsigned char l=0; l<UCHAR_MAX; l++) {
        u = toupper(l);
        if (l!=u) printf("%c%c ", l,u);
    }
    printf("\n\n");
    unsigned char c = '\xb8'; // the character Ž in ISO-8859-15
                              // but ´ (acute accent) in ISO-8859-1 
    unsigned char c2 = c;   // for printing
    setlocale(LC_ALL, "en_US.iso88591");
    printf("in iso8859-1, toupper('0x%x') gives 0x%x\n", c2, toupper(c));
    setlocale(LC_ALL, "en_US.iso885915");
    printf("in iso8859-15, toupper('0x%x') gives 0x%x\n", c2, toupper(c));
}

