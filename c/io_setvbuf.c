/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_setvbuf.exe ./c/io_setvbuf.c && (cd ../_build/c/;./io_setvbuf.exe)
https://en.cppreference.com/w/c/io/setvbuf
*/
#include <stdio.h>
int main(void) {
    char buf[BUFSIZ];
    setbuf(stdin, buf);
} // lifetime of buf ends, undefined behavior

