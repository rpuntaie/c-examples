/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_tmpnam.exe ./cpp/io_c_tmpnam.cpp && (cd ../_build/cpp/;./io_c_tmpnam.exe)
https://en.cppreference.com/w/cpp/io/c/tmpnam
*/
#include <iostream>
#include <cstdio>
#include <string>
int main()
{
    std::string name1 = std::tmpnam(nullptr);
    std::cout << "temporary file name: " << name1 << '\n';
    char name2[L_tmpnam];
    if (std::tmpnam(name2)) {
        std::cout << "temporary file name: " << name2 << '\n';
    }
}

