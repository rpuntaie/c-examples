/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_fill_n.exe ./cpp/algorithm_ranges_fill_n.cpp && (cd ../_build/cpp/;./algorithm_ranges_fill_n.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/fill_n
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
auto print(const auto& v) {
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}
int main()
{
    constexpr auto n{8};
    std::vector<std::string> v(n, "░░");
    print(v);
    std::ranges::fill_n(v.begin(), n, "▓▓");
    print(v);
}

