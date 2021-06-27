/*
gcc -std=c99 -pthread -o ../_build/c/language_storage_duration_3.exe ./c/language_storage_duration_3.c && (cd ../_build/c/;./language_storage_duration_3.exe)
https://en.cppreference.com/w/c/language/storage_duration
*/
#include <stdio.h>
#include <stdlib.h>
/* static storage duration */
int A;
int main(void)
{
    printf("&A = %p\n", (void*)&A);
    /* automatic storage duration */
    int A = 1;   // hides global A
    printf("&A = %p\n", (void*)&A);
    /* allocated storage duration */
    int *ptr_1 = malloc(sizeof(int));   /* start allocated storage duration */
    printf("address of int in allocated memory = %p\n", (void*)ptr_1);
    free(ptr_1);                        /* stop allocated storage duration  */
}

