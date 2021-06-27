/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_is_placeholder.exe ./cpp/utility_functional_is_placeholder.cpp && (cd ../_build/cpp/;./utility_functional_is_placeholder.exe)
https://en.cppreference.com/w/cpp/utility/functional/is_placeholder
*/
#include <iostream>
#include <type_traits>
#include <functional>
struct My_2 {
} my_2;
namespace std {
    template<>
    struct is_placeholder<My_2> : public integral_constant<int, 2> {};
}
int f(int n1, int n2)
{
    return n1+n2;
}
int main()
{
    std::cout << "Standard placeholder _5 is for the argument number "
              << std::is_placeholder<decltype(std::placeholders::_5)>::value
              << '\n';
    auto b = std::bind(f, my_2, 2);
    std::cout << "Adding 2 to 11 selected with a custom placeholder gives " 
              << b(10, 11) // the first argument, namely 10, is ignored
              << '\n';
}

