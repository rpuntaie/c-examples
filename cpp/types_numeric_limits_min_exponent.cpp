/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_numeric_limits_min_exponent.exe ./cpp/types_numeric_limits_min_exponent.cpp && (cd ../_build/cpp/;./types_numeric_limits_min_exponent.exe)
https://en.cppreference.com/w/cpp/types/numeric_limits/min_exponent
*/
#include <iostream>
int main()
{
    std::cout << "min() = " << std::numeric_limits<float>::min() << '\n'
              << "min_exponent10 = " << std::numeric_limits<float>::min_exponent10 << '\n'
              << std::hexfloat
              << "min() = " << std::numeric_limits<float>::min() << '\n'
              << "min_exponent = " << std::numeric_limits<float>::min_exponent << '\n';
}

