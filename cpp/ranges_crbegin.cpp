/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_crbegin.exe ./cpp/ranges_crbegin.cpp && (cd ../_build/cpp/;./ranges_crbegin.exe)
https://en.cppreference.com/w/cpp/ranges/crbegin
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <span>
int main() 
{
    std::vector<int> v = { 3, 1, 4 };
    auto vi = std::ranges::crbegin(v);
    std::cout << *vi << '\n'; 
    int a[] = { -5, 10, 15 };
    auto ai = std::ranges::crbegin(a);
    std::cout << *ai << '\n';
    // auto x_x = std::ranges::crbegin(std::vector<int>{6,6,6});
    // ill-formed: the argument is an rvalue (see Notes ↑)
    auto si = std::ranges::crbegin(std::span{a}); // OK:
    static_assert(std::ranges::enable_borrowed_range<
        std::remove_cv_t<decltype(std::span{a})>>);
    std::cout << *si << '\n';
}

