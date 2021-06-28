/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_islower.exe ./c/string_byte_islower.c && (cd ../_build/c/;./string_byte_islower.exe)
https://en.cppreference.com/w/c/string/byte/islower
*/
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
int main(void)
{
    unsigned char c = '\xe5'; // letter å in ISO-8859-1
    printf("In the default C locale, \\xe5 is %slowercase\n",
           islower(c) ? "" : "not " );
    setlocale(LC_ALL, "en_GB.iso88591");
    printf("In ISO-8859-1 locale, \\xe5 is %slowercase\n",
           islower(c) ? "" : "not " );
}

