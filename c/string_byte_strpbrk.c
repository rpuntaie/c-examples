/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_strpbrk.exe ./c/string_byte_strpbrk.c && (cd ../_build/c/;./string_byte_strpbrk.exe)
https://en.cppreference.com/w/c/string/byte/strpbrk
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    const char* str = "hello world, friend of mine!";
    const char* sep = " ,!";
    unsigned int cnt = 0;
    do {
       str = strpbrk(str, sep); // find separator
       if(str) str += strspn(str, sep); // skip separator
       ++cnt; // increment word count
    } while(str && *str);
    printf("There are %u words\n", cnt);
}

