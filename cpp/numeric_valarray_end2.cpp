/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_end2.exe ./cpp/numeric_valarray_end2.cpp && (cd ../_build/cpp/;./numeric_valarray_end2.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/end2
*/
#include <iostream>
#include <valarray>
#include <algorithm>
int main()
{
    const std::valarray<char> va {
        'H', 'e', 'l', 'l', 'o', 
        ',', ' ', 
        'C', '+', '+', '!', '\n'
    };
    std::for_each(
        std::begin(va),
        std::end(va),
        [](char c) {
            std::cout << c;
        });
}

