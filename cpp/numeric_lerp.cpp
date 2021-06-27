/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_lerp.exe ./cpp/numeric_lerp.cpp && (cd ../_build/cpp/;./numeric_lerp.exe)
https://en.cppreference.com/w/cpp/numeric/lerp
*/
#include <iostream>
#include <cmath>
int main()
{
    float a=10.0f, b=20.0f;
    std::cout << "a=" << a << ", " << "b=" << b << '\n'
              << "mid point=" << std::lerp(a,b,0.5f) << '\n'
              << std::boolalpha << (a == std::lerp(a,b,0.0f)) << ' '
              << std::boolalpha << (b == std::lerp(a,b,1.0f)) << '\n';
}

