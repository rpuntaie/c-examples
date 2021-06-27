/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_partition_point.exe ./cpp/algorithm_partition_point.cpp && (cd ../_build/cpp/;./algorithm_partition_point.exe)
https://en.cppreference.com/w/cpp/algorithm/partition_point
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
int main()
{
    std::array<int, 9> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto is_even = [](int i){ return i % 2 == 0; };
    std::partition(v.begin(), v.end(), is_even);
    auto p = std::partition_point(v.begin(), v.end(), is_even);
    std::cout << "Before partition: ";
    std::copy(v.begin(), p, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nAfter partition:  ";
    std::copy(p, v.end(), std::ostream_iterator<int>(std::cout, " "));
}

