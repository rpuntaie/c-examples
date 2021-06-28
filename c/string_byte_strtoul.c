/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_strtoul.exe ./c/string_byte_strtoul.c && (cd ../_build/c/;./string_byte_strtoul.exe)
https://en.cppreference.com/w/c/string/byte/strtoul
*/
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
int main(void)
{
    const char *p = "10 200000000000000000000000000000 30 -40";
    printf("Parsing '%s':\n", p);
    char *end;
    for (unsigned long i = strtoul(p, &end, 10);
         p != end;
         i = strtoul(p, &end, 10))
    {
        printf("'%.*s' -> ", (int)(end-p), p);
        p = end;
        if (errno == ERANGE){
            printf("range error, got ");
            errno = 0;
        }
        printf("%lu\n", i);
    }
}

