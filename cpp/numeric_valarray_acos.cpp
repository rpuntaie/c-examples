/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_acos.exe ./cpp/numeric_valarray_acos.cpp && (cd ../_build/cpp/;./numeric_valarray_acos.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/acos
*/
#include <cmath>
#include <iostream>
#include <valarray>
const double pi = 4.0 * atan(1.0);
int main()
{
    // take common x-values from unit circle
    const double s32 = std::sqrt(3.0) / 2.0;
    const double s22 = std::sqrt(2.0) / 2.0;
    std::valarray<double> v1 = {-1.0, -s32, -s22, -0.5, 0.0, 0.5, s22, s32, 1.0};
    std::valarray<double> v2 = std::acos(v1) * 180.0 / pi;
    for(double n : v2)
        std::cout << n << "° ";
    std::cout << '\n';
}

