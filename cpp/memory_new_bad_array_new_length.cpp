/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_new_bad_array_new_length.exe ./cpp/memory_new_bad_array_new_length.cpp && (cd ../_build/cpp/;./memory_new_bad_array_new_length.exe)
https://en.cppreference.com/w/cpp/memory/new/bad_array_new_length
*/
#include <iostream>
#include <new>
#include <climits>
int main()
{
    try {
        int negative = -1;
        new int[negative];
    } catch(const std::bad_array_new_length &e) {
        std::cout << "1) " << e.what() << ": negative size\n";
    }
    try {
        int small = 1;
        new int[small]{1,2,3};
    } catch(const std::bad_array_new_length &e) {
        std::cout << "2) " << e.what() << ": too many initializers\n";
    }
    try {
        long large = LONG_MAX;
        new int[large][1000];
    } catch(const std::bad_array_new_length &e) {
        std::cout << "3) " << e.what() << ": too large\n";
    }
    std::cout << "End\n";
}

