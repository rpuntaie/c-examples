/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_ranges_swap.exe ./cpp/utility_ranges_swap.cpp && (cd ../_build/cpp/;./utility_ranges_swap.exe)
https://en.cppreference.com/w/cpp/utility/ranges/swap
*/
#include <array>
#include <concepts>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>
void print(std::string_view const name, 
           std::ranges::common_range auto const& p, 
           std::ranges::common_range auto const& q)
{
    std::cout << name << "1{ ";
    for (auto const& i : p) std::cout << i << ' ';
    std::cout << "}, " << name << "2{ ";
    for (auto const& i : q) std::cout << i << ' ';
    std::cout << "}\n";
}
void print(std::string_view const name, int p, int q)
{
    std::cout << name << "1 = " << p << ", " << name << "2 = " << q << '\n';
}
int main()
{
    std::vector a1{10,11,12}, a2{13,14};
    std::ranges::swap(a1, a2);
    print("a", a1, a2);
    std::array b1{15,16,17}, b2{18,19,20};
    std::ranges::swap(b1, b2);
    print("b", b1, b2);
    // std::array c1{1,2,3}; std::array c2{4,5};
    // std::ranges::swap(c1, c2); // error: types mismatch
    int d1[]{21,22,23}, d2[]{24,25,26};
    std::ranges::swap(d1, d2);
    print("d", d1, d2);
    // int e1[]{1,2,3}, e2[]{4,5};
    // std::ranges::swap(e1, e2); // error: types mismatch
    // char f1[]{1,2,3};
    // int  f2[]{4,5,6};
    // std::ranges::swap(f1, f2); // error: types mismatch
    int g1{27}, g2{28};
    std::ranges::swap(g1, g2);
    print("g", g1, g2);
}

