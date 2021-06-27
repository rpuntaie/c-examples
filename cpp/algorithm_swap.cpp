/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_swap.exe ./cpp/algorithm_swap.cpp && (cd ../_build/cpp/;./algorithm_swap.exe)
https://en.cppreference.com/w/cpp/algorithm/swap
*/
#include <algorithm>
#include <iostream>
int main()
{
    int a = 5, b = 3;
    // before
    std::cout << a << ' ' << b << '\n';
    std::swap(a,b);
    // after
    std::cout << a << ' ' << b << '\n';
}

