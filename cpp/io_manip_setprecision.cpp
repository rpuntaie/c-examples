/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_setprecision.exe ./cpp/io_manip_setprecision.cpp && (cd ../_build/cpp/;./io_manip_setprecision.exe)
https://en.cppreference.com/w/cpp/io/manip/setprecision
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
int main()
{
    const long double pi = std::acos(-1.L);
    std::cout << "default precision (6): " << pi << '\n'
              << "std::setprecision(10): " << std::setprecision(10) << pi << '\n'
              << "max precision:         "
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              << pi << '\n';
}

