/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_filter_view_2.exe ./cpp/ranges_filter_view_2.cpp && (cd ../_build/cpp/;./ranges_filter_view_2.exe)
https://en.cppreference.com/w/cpp/ranges/filter_view
*/
#include <iostream>
#include <ranges>
int main() {
    const auto ints = {0, 1, 2, 3, 4, 5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
    for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
    }
}

