/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_isgraph.exe ./c/string_byte_isgraph.c && (cd ../_build/c/;./string_byte_isgraph.exe)
https://en.cppreference.com/w/c/string/byte/isgraph
*/
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
int main(void)
{
    unsigned char c = '\xb6'; // the character ¶ in ISO-8859-1
    printf("In the default C locale, \\xb6 is %sgraphical\n",
           isgraph(c) ? "" : "not " );
    setlocale(LC_ALL, "en_GB.iso88591");
    printf("In ISO-8859-1 locale, \\xb6 is %sgraphical\n",
           isgraph(c) ? "" : "not " );
}

