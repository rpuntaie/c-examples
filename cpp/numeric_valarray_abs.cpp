/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_abs.exe ./cpp/numeric_valarray_abs.cpp && (cd ../_build/cpp/;./numeric_valarray_abs.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/abs
*/
#include <valarray>
#include <iostream>
int main()
{
    std::valarray<int> v{1, -2, 3, -4, 5, -6, 7, -8};
    std::valarray<int> v2 = std::abs(v);
    for(auto n : v2) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

