/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_fopen.exe ./c/io_fopen.c && (cd ../_build/c/;./io_fopen.exe)
https://en.cppreference.com/w/c/io/fopen
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int is_ok = EXIT_FAILURE;
    const char* fname = "/tmp/unique_name.txt"; // or tmpnam(NULL);
    FILE* fp = fopen(fname, "w+");
    if(!fp) {
        perror("File opening failed");
        return is_ok;
    }
    fputs("Hello, world!\n", fp);
    rewind(fp);
    int c; // note: int, not char, required to handle EOF
    while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
       putchar(c);
    }
    if (ferror(fp)) {
        puts("I/O error when reading");
    } else if (feof(fp)) {
        puts("End of file reached successfully");
        is_ok = EXIT_SUCCESS;
    }
    fclose(fp);
    remove(fname);
    return is_ok;
}

