/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_null_pointer.exe ./cpp/types_is_null_pointer.cpp && (cd ../_build/cpp/;./types_is_null_pointer.exe)
https://en.cppreference.com/w/cpp/types/is_null_pointer
*/
#include <iostream>
#include <type_traits>
int main()
{
    std::cout << std::boolalpha
              << std::is_null_pointer< decltype(nullptr) >::value << ' '
              << std::is_null_pointer< int* >::value << '\n'
              << std::is_pointer< decltype(nullptr) >::value << ' '
              << std::is_pointer<int*>::value << '\n';
}

