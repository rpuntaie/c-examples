/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/comment_4.exe ./c/comment_4.c && (cd ../_build/c/;./comment_4.exe)
https://en.cppreference.com/w/c/comment
*/
#include <stdio.h>
/*
C-style comments can contain
multiple lines.
*/
/* Or, just one line. */
// C++-style comments can comment one line.
// Or, they can
// be strung together.
int main(void)
{
  // The below code won't be run
  // puts("Hello");
  // The below code will be run
  puts("World");
}

