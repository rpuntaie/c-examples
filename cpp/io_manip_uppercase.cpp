/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_uppercase.exe ./cpp/io_manip_uppercase.cpp && (cd ../_build/cpp/;./io_manip_uppercase.exe)
https://en.cppreference.com/w/cpp/io/manip/uppercase
*/
#include <iostream>
int main()
{
    std::cout << std::hex << std::showbase
              << "0x2a with uppercase: " << std::uppercase << 0x2a << '\n'
              << "0x2a with nouppercase: " << std::nouppercase << 0x2a << '\n'
              << "1e-10 with uppercase: " << std::uppercase << 1e-10 << '\n'
              << "1e-10 with nouppercase: " << std::nouppercase << 1e-10 << '\n';
}

