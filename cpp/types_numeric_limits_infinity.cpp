/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_numeric_limits_infinity.exe ./cpp/types_numeric_limits_infinity.cpp && (cd ../_build/cpp/;./types_numeric_limits_infinity.exe)
https://en.cppreference.com/w/cpp/types/numeric_limits/infinity
*/
#include <iostream>
#include <limits>
int main()
{
    double max = std::numeric_limits<double>::max();
    double inf = std::numeric_limits<double>::infinity();
    if(inf > max)
        std::cout << inf << " is greater than " << max << '\n';
}

