/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_skipws.exe ./cpp/io_manip_skipws.cpp && (cd ../_build/cpp/;./io_manip_skipws.exe)
https://en.cppreference.com/w/cpp/io/manip/skipws
*/
#include <iostream>
#include <sstream>
int main()
{
    char c1, c2, c3;
    std::istringstream("a b c") >> c1 >> c2 >> c3;
    std::cout << "Default  behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
    std::istringstream("a b c") >> std::noskipws >> c1 >> c2 >> c3;
    std::cout << "noskipws behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
}

