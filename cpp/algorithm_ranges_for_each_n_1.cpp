/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_for_each_n_1.exe ./cpp/algorithm_ranges_for_each_n_1.cpp && (cd ../_build/cpp/;./algorithm_ranges_for_each_n_1.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/for_each_n
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <string_view>
#include <utility>
using P = const std::pair<int, char>;
std::ostream& operator<< (std::ostream& os, const P& p) {
    return os << '{' << p.first << ",'" << p.second << "'}";
}
auto print = [](std::string_view name, std::ranges::forward_range auto const& v) {
    std::cout << name << ": ";
    for (const auto& e: v) { std::cout << e << ", "; }
    std::cout << '\n';
};
int main()
{
    std::array a{1, 2, 3, 4, 5};
    print("a", a);
    // Negate first three numbers:
    std::ranges::for_each_n(a.begin(), 3, [](auto& n) { n *= -1; });
    print("a", a);
    std::array s{ P{1,'a'}, P{2, 'b'}, P{3, 'c'}, P{4, 'd'} };
    print("s", s);
    // Negate data members 'pair::first' using projection:
    std::ranges::for_each_n(s.begin(), 2, [](auto& x) { x *= -1; }, &P::first);
    print("s", s);
    // Capitalize data members 'pair::second' using projection:
    std::ranges::for_each_n(s.begin(), 3, [](auto& c) { c -= 'a'-'A'; }, &P::second);
    print("s", s);
}

