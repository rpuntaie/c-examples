/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_rename.exe ./c/io_rename.c && (cd ../_build/c/;./io_rename.exe)
https://en.cppreference.com/w/c/io/rename
*/
#include <stdio.h>
int main(void)
{
    FILE* fp = fopen("from.txt", "w"); // create file "from.txt"
    if(!fp) { perror("from.txt"); return 1; }
    fputc('a', fp); // write to "from.txt"
    fclose(fp);
    int rc = rename("from.txt", "to.txt");
    if(rc) { perror("rename"); return 1; }
    fp = fopen("to.txt", "r");
    if(!fp) { perror("to.txt"); return 1; }
    printf("%c\n", fgetc(fp)); // read from "to.txt"
    fclose(fp);
}

