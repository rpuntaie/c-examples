/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_end.exe ./cpp/ranges_end.cpp && (cd ../_build/cpp/;./ranges_end.exe)
https://en.cppreference.com/w/cpp/ranges/end
*/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
int main() 
{
    std::vector<int> v = { 3, 1, 4 };
    namespace ranges = std::ranges;
    if (ranges::find(v, 5) != ranges::end(v)) {
        std::cout << "found a 5 in vector v!\n";
    }
    int a[] = { 5, 10, 15 };
    if (ranges::find(a, 5) != ranges::end(a)) {
        std::cout << "found a 5 in array a!\n";
    }
}

