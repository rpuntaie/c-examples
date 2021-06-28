/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_strcmp.exe ./c/string_byte_strcmp.c && (cd ../_build/c/;./string_byte_strcmp.exe)
https://en.cppreference.com/w/c/string/byte/strcmp
*/
#include <string.h>
#include <stdio.h>
void demo(const char* lhs, const char* rhs)
{
    int rc = strcmp(lhs, rhs);
    const char *rel = rc < 0 ? "precedes" : rc > 0 ? "follows" : "equals";
    printf("[%s] %s [%s]\n", lhs, rel, rhs);
}
int main(void)
{
    const char* string = "Hello World!";
    demo(string, "Hello!");
    demo(string, "Hello");
    demo(string, "Hello there");
    demo("Hello, everybody!" + 12, "Hello, somebody!" + 11);
}

