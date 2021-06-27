/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_isalpha.exe ./c/string_byte_isalpha.c && (cd ../_build/c/;./string_byte_isalpha.exe)
https://en.cppreference.com/w/c/string/byte/isalpha
*/
#include <ctype.h>
#include <stdio.h>
#include <locale.h>
int main(void)
{
    unsigned char c = '\xdf'; // German letter ß in ISO-8859-1
    printf("isalpha('\\xdf') in default C locale returned %d\n", !!isalpha(c));
    setlocale(LC_CTYPE, "de_DE.iso88591");
    printf("isalpha('\\xdf') in ISO-8859-1 locale returned %d\n", !!isalpha(c));
}

