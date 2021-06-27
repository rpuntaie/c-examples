/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_adjacent_difference_1.exe ./cpp/algorithm_adjacent_difference_1.cpp && (cd ../_build/cpp/;./algorithm_adjacent_difference_1.exe)
https://en.cppreference.com/w/cpp/algorithm/adjacent_difference
*/
#include <numeric>
#include <vector>
#include <array>
#include <iostream>
#include <functional>
#include <iterator>
int main()
{
    // Default implementation - the difference b/w two adjacent items
    std::vector v {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    std::adjacent_difference(v.begin(), v.end(), v.begin());
    for (auto n : v)
        std::cout << n << ' ';
    std::cout << '\n';
    // Fibonacci 
    std::array<int, 10> a {1};
    adjacent_difference(begin(a), std::prev(end(a)), std::next(begin(a)), std::plus<> {});
    copy(begin(a), end(a), std::ostream_iterator<int> {std::cout, " "});
}

