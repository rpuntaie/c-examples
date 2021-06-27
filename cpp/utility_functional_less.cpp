/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_less.exe ./cpp/utility_functional_less.cpp && (cd ../_build/cpp/;./utility_functional_less.exe)
https://en.cppreference.com/w/cpp/utility/functional/less
*/
#include <functional>
#include <iostream>
template <typename A, typename B, typename C = std::less<>>
bool fun(A a, B b, C cmp = C{})
{
    return cmp(a, b);
}
int main()
{
    std::cout
      << std::boolalpha
      << fun(1, 2)   << ' ' // true
      << fun(1.0, 1) << ' ' // false
      << fun(1, 2.0) << ' ' // true
      << std::less<int>{}(5, 5.6)    << ' ' // false: 5 < 5 (warn: implicit conversion)
      << std::less<double>{}(5, 5.6) << ' ' // true: 5.0 < 5.6
      << std::less<int>{}(5.6, 5.7)  << ' ' // false: 5 < 5 (warn: implicit conversion)
      << std::less{}(5, 5.6)         << ' ' // true: less<void>: 5.0 < 5.6
      << '\n';
}

