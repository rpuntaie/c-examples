/*
gcc -std=c99 -pthread -o ../_build/c/numeric_random_srand.exe ./c/numeric_random_srand.c && (cd ../_build/c/;./numeric_random_srand.exe)
https://en.cppreference.com/w/c/numeric/random/srand
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    srand(time(NULL)); //use current time as seed for random generator
    int random_variable = rand();
    printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);
}

