/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_iscntrl.exe ./c/string_byte_iscntrl.c && (cd ../_build/c/;./string_byte_iscntrl.exe)
https://en.cppreference.com/w/c/string/byte/iscntrl
*/
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
int main(void)
{
    unsigned char c = '\x94'; // the control code CCH in ISO-8859-1
    printf("In the default C locale, \\x94 is %sa control character\n",
           iscntrl(c) ? "" : "not " );
    setlocale(LC_ALL, "en_GB.iso88591");
    printf("In ISO-8859-1 locale, \\x94 is %sa control character\n",
           iscntrl(c) ? "" : "not " );
}

