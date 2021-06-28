/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_ispunct.exe ./c/string_byte_ispunct.c && (cd ../_build/c/;./string_byte_ispunct.exe)
https://en.cppreference.com/w/c/string/byte/ispunct
*/
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
int main(void)
{
    unsigned char c = '\xd7'; // the character × (multiplication sign) in ISO-8859-1
    printf("In the default C locale, \\xd7 is %spunctuation\n",
           ispunct(c) ? "" : "not " );
    setlocale(LC_ALL, "en_GB.iso88591");
    printf("In ISO-8859-1 locale, \\xd7 is %spunctuation\n",
           ispunct(c) ? "" : "not " );
}

