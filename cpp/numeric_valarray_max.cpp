/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_max.exe ./cpp/numeric_valarray_max.cpp && (cd ../_build/cpp/;./numeric_valarray_max.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/max
*/
#include <valarray>
#include <iostream>
int main()
{
    std::valarray<double> a{1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "Maximum value : " << a.max() << "\n";
}

