/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_compare_compare_weak_order_fallback_1.exe ./cpp/utility_compare_compare_weak_order_fallback_1.cpp && (cd ../_build/cpp/;./utility_compare_compare_weak_order_fallback_1.exe)
https://en.cppreference.com/w/cpp/utility/compare/compare_weak_order_fallback
*/
#include <iostream>
#include <compare>
#include <concepts>
// does not support <=>
struct Rational_1 {
    int num;
    int den; // > 0
};
inline constexpr bool operator<(Rational_1 lhs, Rational_1 rhs)
{
    return lhs.num * rhs.den < rhs.num * lhs.den;
}
inline constexpr bool operator==(Rational_1 lhs, Rational_1 rhs)
{
    return lhs.num * rhs.den == rhs.num * lhs.den;
}
// supports <=>
struct Rational_2 {
    int num;
    int den; // > 0
};
inline constexpr std::weak_ordering operator<=>(Rational_2 lhs, Rational_2 rhs)
{
    return lhs.num * rhs.den <=> rhs.num * lhs.den;
}
void print(std::weak_ordering value)
{
    if (value == 0)
        std::cout << "equal\n";
    else if (value < 0)
        std::cout << "less\n";
    else
        std::cout << "greater\n";
}
int main()
{
    Rational_1 a{1, 2};
    Rational_1 b{3, 4};
//  print(a <=> b);                // doesn't work
    print(std::compare_weak_order_fallback(a, b)); // works, defaults to < and ==
    Rational_2 c{6, 5};
    Rational_2 d{8, 7};
    print(c <=> d);                // works
    // print(std::compare_weak_order_fallback(c, d)); // works ?? (not with g++ 11.1)
}

