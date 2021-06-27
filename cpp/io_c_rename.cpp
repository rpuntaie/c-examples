/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_rename.exe ./cpp/io_c_rename.cpp && (cd ../_build/cpp/;./io_c_rename.exe)
https://en.cppreference.com/w/cpp/io/c/rename
*/
#include <iostream>
#include <fstream>
#include <cstdio>
int main()
{
    bool ok{std::ofstream("from.txt").put('a')}; // create and write to file
    if (!ok) {
        std::perror("Error creating from.txt");
        return 1;
    }
    if (std::rename("from.txt", "to.txt")) {
        std::perror("Error renaming");
        return 1;
    }
    std::cout << std::ifstream("to.txt").rdbuf() << '\n'; // print file
}

