/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_prev.exe ./cpp/iterator_prev.cpp && (cd ../_build/cpp/;./iterator_prev.exe)
https://en.cppreference.com/w/cpp/iterator/prev
*/
#include <iostream>
#include <iterator>
#include <vector>
int main() 
{
    std::vector<int> v{ 3, 1, 4 };
    auto it = v.end();
    auto pv = std::prev(it, 2);
    std::cout << *pv << '\n';
    it = v.begin();
    pv = std::prev(it, -2);
    std::cout << *pv << '\n';
}

