/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_partition_point.exe ./cpp/algorithm_ranges_partition_point.cpp && (cd ../_build/cpp/;./algorithm_ranges_partition_point.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/partition_point
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
int main()
{
    std::array v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    namespace ranges = std::ranges;
    auto is_even = [](int i){ return i % 2 == 0; };
    ranges::partition(v, is_even);
    auto p = ranges::partition_point(v.begin(), v.end(), is_even);
    std::cout << "Before partition:\n    ";
    ranges::copy(v.begin(), p, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nAfter partition:\n    ";
    ranges::copy(p, v.end(), std::ostream_iterator<int>(std::cout, " "));
}

