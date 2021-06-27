/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_values_view.exe ./cpp/ranges_values_view.cpp && (cd ../_build/cpp/;./ranges_values_view.exe)
https://en.cppreference.com/w/cpp/ranges/values_view
*/
#include <iostream>
#include <ranges>
#include <map>
int main()
{
    std::map<char, int> map{ {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5} };
    auto odd = [](int x) { return 0 != (x & 1); };
    std::cout << "Odd values in the map: ";
    for (int value : map | std::views::values | std::views::filter(odd))
        std::cout << value << ' ';
}

