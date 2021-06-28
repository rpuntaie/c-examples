/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_strrchr.exe ./c/string_byte_strrchr.c && (cd ../_build/c/;./string_byte_strrchr.exe)
https://en.cppreference.com/w/c/string/byte/strrchr
*/
#include <string.h>
#include <stdio.h>
int main(void)
{
    char szSomeFileName[] = "foo/bar/foobar.txt";
    char *pLastSlash = strrchr(szSomeFileName, '/');
    char *pszBaseName = pLastSlash ? pLastSlash + 1 : szSomeFileName;
    printf("Base Name: %s", pszBaseName);
}

