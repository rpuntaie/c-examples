/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_errc_make_error_condition.exe ./cpp/error_errc_make_error_condition.cpp && (cd ../_build/cpp/;./error_errc_make_error_condition.exe)
https://en.cppreference.com/w/cpp/error/errc/make_error_condition
*/
#include <system_error>
#include <string>
#include <iostream>
int main()
{
    auto err = std::make_error_condition(std::errc::invalid_argument);
    std::cout << err.message() << '\n';
}

