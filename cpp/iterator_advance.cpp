/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_advance.exe ./cpp/iterator_advance.cpp && (cd ../_build/cpp/;./iterator_advance.exe)
https://en.cppreference.com/w/cpp/iterator/advance
*/
#include <iostream>
#include <iterator>
#include <vector>
int main() 
{
    std::vector<int> v{ 3, 1, 4 };
    auto vi = v.begin();
    std::advance(vi, 2);
    std::cout << *vi << ' ';
    vi = v.end();
    std::advance(vi, -2);
    std::cout << *vi << '\n';
}

