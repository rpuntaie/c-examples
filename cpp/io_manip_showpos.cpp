/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_showpos.exe ./cpp/io_manip_showpos.cpp && (cd ../_build/cpp/;./io_manip_showpos.exe)
https://en.cppreference.com/w/cpp/io/manip/showpos
*/
#include <iostream>
int main()
{
    std::cout
        << "showpos: " << std::showpos << 42 << ' ' << 3.14 << ' ' << 0 << '\n'
        << "noshowpos: " << std::noshowpos << 42 << ' ' << 3.14 << ' ' << 0 << '\n';
}

