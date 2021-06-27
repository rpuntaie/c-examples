/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_size.exe ./cpp/numeric_valarray_size.cpp && (cd ../_build/cpp/;./numeric_valarray_size.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/size
*/
#include <iostream>
#include <valarray>
int main()
{
    std::valarray<double> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Average: " << a.sum()/a.size() << '\n';
}

