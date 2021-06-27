/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_cend.exe ./cpp/ranges_cend.cpp && (cd ../_build/cpp/;./ranges_cend.exe)
https://en.cppreference.com/w/cpp/ranges/cend
*/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
int main() 
{
    std::vector<int> v = { 3, 1, 4 };
    namespace ranges = std::ranges;
    if (ranges::find(v, 5) != ranges::cend(v)) {
        std::cout << "found a 5 in vector v!\n";
    }
    int a[] = { 5, 10, 15 };
    if (ranges::find(a, 5) != ranges::cend(a)) {
        std::cout << "found a 5 in array a!\n";
    }
}

