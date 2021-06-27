/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_resize.exe ./cpp/numeric_valarray_resize.cpp && (cd ../_build/cpp/;./numeric_valarray_resize.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/resize
*/
#include <valarray>
#include <iostream>
int main()
{
    std::valarray<int> v{1,2,3};
    v.resize(10);
    for(int n: v) std::cout << n << ' ';
    std::cout << '\n';
}

