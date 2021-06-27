/*
gcc -std=c99 -pthread -o ../_build/c/io_setvbuf.exe ./c/io_setvbuf.c && (cd ../_build/c/;./io_setvbuf.exe)
https://en.cppreference.com/w/c/io/setvbuf
*/
int main(void) {
    char buf[BUFSIZ];
    setbuf(stdin, buf);
} // lifetime of buf ends, undefined behavior

