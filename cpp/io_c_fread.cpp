/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_fread.exe ./cpp/io_c_fread.cpp && (cd ../_build/cpp/;./io_c_fread.exe)
https://en.cppreference.com/w/cpp/io/c/fread
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
int main()
{
    // prepare file
    std::ofstream("test.txt") << 1 << ' ' << 2 << '\n';
    std::FILE* f = std::fopen("test.txt", "r");
    std::vector<char> buf(4); // char is trivally copyable
    std::fread(&buf[0], sizeof buf[0], buf.size(), f);
    for(char n : buf)
        std::cout << n;
    std::vector<std::string> buf2; // string is not trivially copyable
// this would result in undefined behavior
//    std::fread(&buf2[0], sizeof buf2[0], buf2.size(), f);
}

