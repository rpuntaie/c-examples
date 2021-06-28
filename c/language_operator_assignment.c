/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_operator_assignment.exe ./c/language_operator_assignment.c #segfault: && (cd ../_build/c/;./language_operator_assignment.exe)
https://en.cppreference.com/w/c/language/operator_assignment
*/
#include <stdio.h>
int main(void)
{
    const char **cpp;
    char *p;
    const char c = 'A';
//  cpp = &p;  // Error: char** is not convertible to const char**
    *cpp = &c; // OK, char* is convertible to const char*
    *p = 0;    // OK, null pointer constant is convertible to any pointer
    int arr1[2] = {1,2}, arr2[2] = {3, 4};
//  arr1 = arr2; // Error: cannot assign to an array
    struct s { 
         int arr[2]; // an array wrapped in a struct
    } sam1 = {5, 6}, sam2 = {7, 8};
    sam1 = sam2; // OK: can assign arrays wrapped in structs
    printf("%d %d \n",sam1.arr[0],sam1.arr[1]);
}

