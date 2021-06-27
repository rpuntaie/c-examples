/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_variant_size.exe ./cpp/utility_variant_variant_size.cpp && (cd ../_build/cpp/;./utility_variant_variant_size.exe)
https://en.cppreference.com/w/cpp/utility/variant/variant_size
*/
#include <any>
#include <cstdio>
#include <variant>
static_assert(std::variant_size_v<std::variant<>> == 0);
static_assert(std::variant_size_v<std::variant<int>> == 1);
static_assert(std::variant_size_v<std::variant<int, int>> == 2);
static_assert(std::variant_size_v<std::variant<int, int, int>> == 3);
static_assert(std::variant_size_v<std::variant<int, float, double>> == 3);
static_assert(std::variant_size_v<std::variant<std::monostate, void>> == 2);
static_assert(std::variant_size_v<std::variant<const int, const float>> == 2);
static_assert(std::variant_size_v<std::variant<std::variant<std::any>>> == 1);
int main() { std::puts("All static assertions passed."); }

