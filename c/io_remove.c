/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/io_remove.exe ./c/io_remove.c && (cd ../_build/c/;./io_remove.exe)
https://en.cppreference.com/w/c/io/remove
*/
#include <stdio.h>
int main(void)
{
    FILE* fp = fopen("file1.txt", "w"); // create file
    if(!fp) { perror("file1.txt"); return 1; }
    puts("Created file1.txt");
    fclose(fp);
    int rc = remove("file1.txt");
    if(rc) { perror("remove"); return 1; }
    puts("Removed file1.txt");
    fp = fopen("file1.txt", "r"); // Failure: file does not exist
    if(!fp) perror("Opening removed file failed");
    rc = remove("file1.txt"); // Failure: file does not exist
    if(rc) perror("Double-remove failed");
}

