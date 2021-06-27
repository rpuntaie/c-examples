/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_setfill.exe ./cpp/io_manip_setfill.cpp && (cd ../_build/cpp/;./io_manip_setfill.exe)
https://en.cppreference.com/w/cpp/io/manip/setfill
*/
#include <iostream>
#include <iomanip>
int main()
{
    std::cout << "default fill: [" << std::setw(10) << 42 << "]\n"
              << "setfill('*'): [" << std::setfill('*')
                                   << std::setw(10) << 42 << "]\n";
}

