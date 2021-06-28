/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_rewind.exe ./c/io_rewind.c && (cd ../_build/c/;./io_rewind.exe)
https://en.cppreference.com/w/c/io/rewind
*/
#include <stdio.h>
char str[20];
int main(void)
{
    FILE *f;
    char ch;
    f = fopen("file.txt", "w");
    for (ch = '0'; ch <= '9'; ch++) {
        fputc(ch, f);
    }
    fclose(f);
    f = fopen("file.txt", "r");
    fread(str, 1, 10, f);
    puts(str);
    rewind(f);
    fread(str, 1, 10, f);
    puts(str);
    fclose(f);
    return 0;
}

