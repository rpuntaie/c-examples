/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_split_view.exe ./cpp/ranges_split_view.cpp && (cd ../_build/cpp/;./ranges_split_view.exe)
https://en.cppreference.com/w/cpp/ranges/split_view
*/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string_view>
auto print = [](auto const& view) {
    for (std::cout << "{ "; const auto element : view)
        std::cout << element << ' ';
    std::cout << "} ";
};
int main()
{
    constexpr static auto source = { 0, 1,0, 2,3,0, 4,5,6,0, 7,8,9 };
    constexpr int delimiter {0};
    constexpr std::ranges::split_view split_view {source, delimiter};
    std::cout << "splits[" << std::ranges::distance(split_view) << "]:  ";
    for (auto const& split: split_view) { print(split); }
    constexpr std::string_view hello { "Hello C++ 20 !" };
    std::cout << "\n" "substrings: ";
    std::ranges::for_each(hello | std::ranges::views::split(' '), print);
}

