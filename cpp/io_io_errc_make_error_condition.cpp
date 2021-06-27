/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_io_errc_make_error_condition.exe ./cpp/io_io_errc_make_error_condition.cpp && (cd ../_build/cpp/;./io_io_errc_make_error_condition.exe)
https://en.cppreference.com/w/cpp/io/io_errc/make_error_condition
*/
#include <iostream>
#include <system_error>
#include <string>
int main()
{
    std::error_condition ec  = std::make_error_condition(std::io_errc::stream);
    std::cout << "error condition for io_errc::stream has value " << ec.value()
              << "\nand message \"" << ec.message() << "\"\n";
}

