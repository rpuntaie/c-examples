/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_fputws.exe ./c/io_fputws.c && (cd ../_build/c/;./io_fputws.exe)
https://en.cppreference.com/w/c/io/fputws
*/
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    int rc = fputws(L"御休みなさい", stdout);
    if (rc == EOF)
       perror("fputws()"); // POSIX requires that errno is set
}

