/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_reverse_view.exe ./cpp/ranges_reverse_view.cpp && (cd ../_build/cpp/;./ranges_reverse_view.exe)
https://en.cppreference.com/w/cpp/ranges/reverse_view
*/
#include <ranges>
#include <iostream>
int main()
{
    static constexpr auto il = {3, 1, 4, 1, 5, 9};
    std::ranges::reverse_view rv {il};
    for (int i : rv)
        std::cout << i << ' ';
    std::cout << '\n';
    for (int i : il | std::views::reverse)
        std::cout << i << ' ';
}

