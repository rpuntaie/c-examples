/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_begin_1.exe ./cpp/iterator_begin_1.cpp && (cd ../_build/cpp/;./iterator_begin_1.exe)
https://en.cppreference.com/w/cpp/iterator/begin
*/
#include <iostream>
#include <vector>
#include <iterator>
int main() 
{
    std::vector<int> v = { 3, 1, 4 };
    auto vi = std::begin(v);
    std::cout << std::showpos << *vi << '\n'; 
    int a[] = { -5, 10, 15 };
    auto ai = std::begin(a);
    std::cout << *ai << '\n';
}

