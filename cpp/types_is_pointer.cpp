/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_pointer.exe ./cpp/types_is_pointer.cpp && (cd ../_build/cpp/;./types_is_pointer.exe)
https://en.cppreference.com/w/cpp/types/is_pointer
*/
#include <iostream>
#include <type_traits>
class A {};
int main() 
{
    std::cout << std::boolalpha;
    std::cout << std::is_pointer<A>::value << '\n';
    std::cout << std::is_pointer<A *>::value << '\n';
    std::cout << std::is_pointer<A &>::value << '\n';
    std::cout << std::is_pointer<int>::value << '\n';
    std::cout << std::is_pointer<int *>::value << '\n';
    std::cout << std::is_pointer<int **>::value << '\n';
    std::cout << std::is_pointer<int[10]>::value << '\n';
    std::cout << std::is_pointer<std::nullptr_t>::value << '\n';
}

