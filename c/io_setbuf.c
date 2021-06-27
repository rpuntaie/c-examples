/*
gcc -std=c99 -pthread -o ../_build/c/io_setbuf.exe ./c/io_setbuf.c && (cd ../_build/c/;./io_setbuf.exe)
https://en.cppreference.com/w/c/io/setbuf
*/
int main(void) {
    char buf[BUFSIZ];
    setbuf(stdin, buf);
} // lifetime of buf ends, undefined behavior

