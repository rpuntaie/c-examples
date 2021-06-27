/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_strspn.exe ./c/string_byte_strspn.c && (cd ../_build/c/;./string_byte_strspn.exe)
https://en.cppreference.com/w/c/string/byte/strspn
*/
#include <string.h>
#include <stdio.h>
int main(void)
{
    const char *string = "abcde312$#@";
    const char *low_alpha = "qwertyuiopasdfghjklzxcvbnm";
    size_t spnsz = strspn(string, low_alpha);
    printf("After skipping initial lowercase letters from '%s'\n"
           "The remainder is '%s'\n", string, string+spnsz);
}

