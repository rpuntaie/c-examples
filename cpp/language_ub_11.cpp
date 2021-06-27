/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_ub_11.exe ./cpp/language_ub_11.cpp && (cd ../_build/cpp/;./language_ub_11.exe)
https://en.cppreference.com/w/cpp/language/ub
*/
#include <iostream>
#include <cstdlib>
int main() {
    int *p = (int*)std::malloc(sizeof(int));
    int *q = (int*)std::realloc(p, sizeof(int));
    *p = 1; // UB access to a pointer that was passed to realloc
    *q = 2;
    if (p == q) // UB access to a pointer that was passed to realloc
        std::cout << *p << *q << '\n';
}

