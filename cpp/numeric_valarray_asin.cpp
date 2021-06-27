/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_asin.exe ./cpp/numeric_valarray_asin.cpp && (cd ../_build/cpp/;./numeric_valarray_asin.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/asin
*/
#include <cmath>
#include <iostream>
#include <valarray>
const double pi = 4.0 * atan(1.0); // C++20: std::numbers::pi
const double s22 = std::sqrt(2.0) / 2.0;
const double s32 = std::sqrt(3.0) / 2.0;
int main()
{
    // take common y-values from unit circle
    const std::valarray<double> v1 = {-1.0, -s32, -s22, -0.5, 0.0, 
                                       0.5,  s22,  s32,  1.0};
    const std::valarray<double> v2 = std::asin(v1) * 180.0 / pi;
    std::cout << std::showpos;
    for(double n : v2)
        std::cout << n << "° ";
    std::cout << '\n';
}

