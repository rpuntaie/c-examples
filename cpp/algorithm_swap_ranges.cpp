/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_swap_ranges.exe ./cpp/algorithm_swap_ranges.cpp && (cd ../_build/cpp/;./algorithm_swap_ranges.exe)
https://en.cppreference.com/w/cpp/algorithm/swap_ranges
*/
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
auto print = [](auto comment, auto const& seq) {
    std::cout << comment;
    for (const auto& e : seq) { std::cout << e << ' '; }
    std::cout << '\n';
};
int main()
{
    std::vector<char> v = {'a', 'b', 'c', 'd', 'e'};
    std::list<char> l = {'1', '2', '3', '4', '5'};
    print("Before swap_ranges:\n" "v: ", v);
    print("l: ", l);
    std::swap_ranges(v.begin(), v.begin()+3, l.begin());
    print("After swap_ranges:\n" "v: ", v);
    print("l: ", l);
}

