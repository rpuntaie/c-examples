/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_setbuf.exe ./c/io_setbuf.c && (cd ../_build/c/;./io_setbuf.exe)
https://en.cppreference.com/w/c/io/setbuf
*/
#include <stdio.h>
int main(void) {
    char buf[BUFSIZ];
    setbuf(stdin, buf);
} // lifetime of buf ends, undefined behavior

