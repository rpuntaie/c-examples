/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_numeric_limits_quiet_NaN.exe ./cpp/types_numeric_limits_quiet_NaN.cpp && (cd ../_build/cpp/;./types_numeric_limits_quiet_NaN.exe)
https://en.cppreference.com/w/cpp/types/numeric_limits/quiet_NaN
*/
#include <iostream>
#include <limits>
#include <cmath>
int main()
{
    std::cout << std::numeric_limits<double>::quiet_NaN() << ' '
              << std::numeric_limits<double>::signaling_NaN() << ' '
              << std::acos(2) << ' '
              << std::tgamma(-1) << ' '
              << std::log(-1) << ' '
              << std::sqrt(-1) << ' '
              << 0 / 0.0 << '\n';
    std::cout << "NaN == NaN? " << std::boolalpha
              << ( std::numeric_limits<double>::quiet_NaN()
                   == std::numeric_limits<double>::quiet_NaN() ) << '\n';
}

