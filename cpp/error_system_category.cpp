/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_system_category.exe ./cpp/error_system_category.cpp && (cd ../_build/cpp/;./error_system_category.exe)
https://en.cppreference.com/w/cpp/error/system_category
*/
#include <iostream>
#include <system_error>
#include <iomanip>
#include <string>
int main()
{
    std::error_condition econd = std::system_category().default_error_condition(EDOM);
    std::cout << "Category: " << econd.category().name() << '\n'
              << "Value: " << econd.value() << '\n'
              << "Message: " << econd.message() << '\n';
    econd = std::system_category().default_error_condition(10001);
    std::cout << "Category: " << econd.category().name() << '\n'
              << "Value: " << econd.value() << '\n'
              << "Message: " << econd.message() << '\n';
}

