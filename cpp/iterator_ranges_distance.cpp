/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_ranges_distance.exe ./cpp/iterator_ranges_distance.cpp && (cd ../_build/cpp/;./iterator_ranges_distance.exe)
https://en.cppreference.com/w/cpp/iterator/ranges/distance
*/
#include <iostream>
#include <iterator>
#include <vector>
int main() 
{
    std::vector<int> v{ 3, 1, 4 };
    namespace ranges = std::ranges;
    std::cout << "distance(first, last) = "
              << ranges::distance(v.begin(), v.end()) << '\n'
              << "distance(last, first) = "
              << ranges::distance(v.end(), v.begin()) << '\n'
              << "distance(v) = " << ranges::distance(v) << '\n';
}

