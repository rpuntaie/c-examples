/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_swap.exe ./cpp/utility_variant_swap.cpp && (cd ../_build/cpp/;./utility_variant_swap.exe)
https://en.cppreference.com/w/cpp/utility/variant/swap
*/
#include <variant>
#include <string>
#include <iostream>
int main()
{
    std::variant<int, std::string> v1{2}, v2{"abc"}; 
    std::visit([] (auto&& x) { std::cout << x << ' '; }, v1);
    std::visit([] (auto&& x) { std::cout << x << '\n'; }, v2);
    v1.swap(v2);
    std::visit([] (auto&& x) { std::cout << x << ' '; }, v1);
    std::visit([] (auto&& x) { std::cout << x << '\n'; }, v2);
}

