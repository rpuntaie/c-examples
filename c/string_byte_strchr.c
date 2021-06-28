/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_byte_strchr.exe ./c/string_byte_strchr.c && (cd ../_build/c/;./string_byte_strchr.exe)
https://en.cppreference.com/w/c/string/byte/strchr
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
  const char *str = "Try not. Do, or do not. There is no try.";
  char target = 'T';
  const char *result = str;
  while((result = strchr(result, target)) != NULL) {
    printf("Found '%c' starting at '%s'\n", target, result);
    ++result; // Increment result, otherwise we'll find target at the same location
  }
}

