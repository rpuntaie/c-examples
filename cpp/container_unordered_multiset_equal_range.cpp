/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multiset_equal_range.exe ./cpp/container_unordered_multiset_equal_range.cpp && (cd ../_build/cpp/;./container_unordered_multiset_equal_range.exe)
https://en.cppreference.com/w/cpp/container/unordered_multiset/equal_range
*/
#include <iostream>
#include <iterator>
#include <unordered_set>
int main()
{
    std::unordered_multiset sequence{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
    std::cout << "The sequence:\n";
    for (int x : sequence) { std::cout << x << ' '; }
    std::cout << "\nNumber:Frequency:\n";
    for (int number{0}; number != 10; ++number) {
        const auto r = sequence.equal_range(number);
        std::cout << number << ":" << std::distance(r.first, r.second) << "; ";
    }
}

