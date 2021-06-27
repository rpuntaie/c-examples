/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_numeric_limits_max_exponent.exe ./cpp/types_numeric_limits_max_exponent.cpp && (cd ../_build/cpp/;./types_numeric_limits_max_exponent.exe)
https://en.cppreference.com/w/cpp/types/numeric_limits/max_exponent
*/
#include <iostream>
#include <limits>
int main()
{
    std::cout << "max() = " << std::numeric_limits<float>::max() << '\n'
              << "max_exponent10 = " << std::numeric_limits<float>::max_exponent10 << '\n'
              << std::hexfloat
              << "max() = " << std::numeric_limits<float>::max() << '\n'
              << "max_exponent = " << std::numeric_limits<float>::max_exponent << '\n';
}

