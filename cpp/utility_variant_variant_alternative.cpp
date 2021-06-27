/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_variant_alternative.exe ./cpp/utility_variant_variant_alternative.cpp && (cd ../_build/cpp/;./utility_variant_variant_alternative.exe)
https://en.cppreference.com/w/cpp/utility/variant/variant_alternative
*/
#include <variant>
#include <iostream>
using my_variant = std::variant<int, float>;
static_assert(std::is_same_v
    <int,   std::variant_alternative_t<0, my_variant>>);
static_assert(std::is_same_v
    <float, std::variant_alternative_t<1, my_variant>>);
// cv-qualification on the variant type propagates to the extracted alternative type.
static_assert(std::is_same_v
    <const int, std::variant_alternative_t<0, const my_variant>>);
int main()
{
    std::cout << "All static assertions passed.\n";
}

