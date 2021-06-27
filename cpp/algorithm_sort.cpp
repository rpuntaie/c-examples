/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_sort.exe ./cpp/algorithm_sort.cpp && (cd ../_build/cpp/;./algorithm_sort.exe)
https://en.cppreference.com/w/cpp/algorithm/sort
*/
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string_view>
int main()
{
    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    auto print = [&s](std::string_view const rem) {
        for (auto a : s) {
            std::cout << a << ' ';
        }
        std::cout << ": " << rem << '\n';
    };
    std::sort(s.begin(), s.end());
    print("sorted with the default operator<");
    std::sort(s.begin(), s.end(), std::greater<int>());
    print("sorted with the standard library compare function object");
    struct {
        bool operator()(int a, int b) const { return a < b; }
    } customLess;
    std::sort(s.begin(), s.end(), customLess);
    print("sorted with a custom function object");
    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;
    });
    print("sorted with a lambda expression");
}

