/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_showbase.exe ./cpp/io_manip_showbase.cpp && (cd ../_build/cpp/;./io_manip_showbase.exe)
https://en.cppreference.com/w/cpp/io/manip/showbase
*/
#include <sstream>
#include <locale>
#include <iostream>
#include <iomanip>
int main()
{
    // showbase affects the output of octals and hexadecimals
    std::cout << std::hex
              << "showbase: " << std::showbase << 42 << '\n'
              << "noshowbase: " << std::noshowbase << 42 << '\n';
    // and both input and output of monetary values
    std::locale::global(std::locale("en_US.utf8"));
    long double val = 0;
    std::istringstream is("3.14");
    is >> std::showbase >> std::get_money(val);
    std::cout << "With showbase, parsing 3.14 as money gives " << val << '\n';
    is.seekg(0);
    is >> std::noshowbase >> std::get_money(val);
    std::cout << "Without showbase, parsing 3.14 as money gives " << val << '\n';
}

