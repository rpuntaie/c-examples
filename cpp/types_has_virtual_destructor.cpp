/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_has_virtual_destructor.exe ./cpp/types_has_virtual_destructor.cpp && (cd ../_build/cpp/;./types_has_virtual_destructor.exe)
https://en.cppreference.com/w/cpp/types/has_virtual_destructor
*/
#include <iostream>
#include <type_traits>
#include <string>
#include <stdexcept>
int main()
{
    std::cout << std::boolalpha
              << "std::string has a virtual destructor? "
              << std::has_virtual_destructor<std::string>::value << '\n'
              << "std::runtime_error has a virtual destructor? "
              << std::has_virtual_destructor<std::runtime_error>::value << '\n';
}

