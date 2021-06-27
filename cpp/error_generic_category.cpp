/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_generic_category.exe ./cpp/error_generic_category.cpp && (cd ../_build/cpp/;./error_generic_category.exe)
https://en.cppreference.com/w/cpp/error/generic_category
*/
#include <iostream>
#include <system_error>
#include <cerrno>
#include <string>
int main()
{
    std::error_condition econd = std::generic_category().default_error_condition(EDOM);
    std::cout << "Category: " << econd.category().name() << '\n'
              << "Value: " << econd.value() << '\n'
              << "Message: " << econd.message() << '\n';
}

