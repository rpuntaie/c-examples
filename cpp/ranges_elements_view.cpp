/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_elements_view.exe ./cpp/ranges_elements_view.cpp && (cd ../_build/cpp/;./ranges_elements_view.exe)
https://en.cppreference.com/w/cpp/ranges/elements_view
*/
#include <iostream>
#include <ranges>
#include <tuple>
#include <vector>
int main()
{
    const std::vector<std::tuple<int, char, std::string>> vt {
        {1, 'A', "α"},
        {2, 'B', "β"},
        {3, 'C', "γ"},
        {4, 'D', "δ"},
        {5, 'E', "ε"},
    };
    for (int const e: std::views::elements<0>(vt)) { std::cout << e << ' '; }
    std::cout << '\n';
    for (char const e: std::views::elements<1>(vt)) { std::cout << e << ' '; }
    std::cout << '\n';
    for (std::string const& e: std::views::elements<2>(vt)) { std::cout << e << ' '; }
    std::cout << '\n';
}

