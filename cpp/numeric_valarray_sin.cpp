/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_sin.exe ./cpp/numeric_valarray_sin.cpp && (cd ../_build/cpp/;./numeric_valarray_sin.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/sin
*/
#include <iostream>
#include <valarray>
#include <cmath>
const double pi = std::acos(-1);
int main()
{
    std::valarray<double> v1 = {0, 0.25, 0.5, 0.75, 1};
    std::valarray<double> v2 = std::sin(v1 * pi);
    for(double n : v2)
        std::cout << std::fixed << n << ' ';
    std::cout << '\n';
}

