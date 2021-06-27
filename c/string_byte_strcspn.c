/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_strcspn.exe ./c/string_byte_strcspn.c && (cd ../_build/c/;./string_byte_strcspn.exe)
https://en.cppreference.com/w/c/string/byte/strcspn
*/
#include <string.h>
#include <stdio.h>
int main(void)
{
    const char *string = "abcde312$#@";
    const char *invalid = "*$#";
    size_t valid_len = strcspn(string, invalid);
    if(valid_len != strlen(string))
       printf("'%s' contains invalid chars starting at position %zu\n",
               string, valid_len);
}

