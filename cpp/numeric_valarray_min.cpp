/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_min.exe ./cpp/numeric_valarray_min.cpp && (cd ../_build/cpp/;./numeric_valarray_min.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/min
*/
#include <valarray>
#include <iostream>
int main()
{
    std::valarray<double> a{1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "Minimum value : " << a.min() << "\n";
}

