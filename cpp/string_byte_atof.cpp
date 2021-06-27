/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_atof.exe ./cpp/string_byte_atof.cpp && (cd ../_build/cpp/;./string_byte_atof.exe)
https://en.cppreference.com/w/cpp/string/byte/atof
*/
#include <cstdlib>
#include <iostream>
int main()
{
    std::cout << std::atof("0.0000000123") << '\n'
              << std::atof("0.012")        << '\n'
              << std::atof("15e16")        << '\n'
              << std::atof("-0x1afp-2")    << '\n'
              << std::atof("inF")          << '\n'
              << std::atof("Nan")          << '\n'
              << std::atof("invalid")      << '\n';
}

