/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/program_getenv.exe ./c/program_getenv.c && (cd ../_build/c/;./program_getenv.exe)
https://en.cppreference.com/w/c/program/getenv
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    const char *name = "PATH";
    const char *env_p = getenv(name);
    if (env_p)
        printf("%s = %s\n", name, env_p);
}

