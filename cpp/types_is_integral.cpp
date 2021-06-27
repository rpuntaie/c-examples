/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_integral.exe ./cpp/types_is_integral.cpp && (cd ../_build/cpp/;./types_is_integral.exe)
https://en.cppreference.com/w/cpp/types/is_integral
*/
#include <iostream>
#include <type_traits>
class A {};
enum E : int {};
template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_integral<A>::value << '\n';
    std::cout << std::is_integral_v<E> << '\n';
    std::cout << std::is_integral_v<float> << '\n';
    std::cout << std::is_integral_v<int> << '\n';
    std::cout << std::is_integral_v<const int> << '\n';
    std::cout << std::is_integral_v<bool> << '\n';
    std::cout << f(123) << '\n';
}

