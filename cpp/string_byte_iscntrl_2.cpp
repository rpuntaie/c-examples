/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_iscntrl_2.exe ./cpp/string_byte_iscntrl_2.cpp && (cd ../_build/cpp/;./string_byte_iscntrl_2.exe)
https://en.cppreference.com/w/cpp/string/byte/iscntrl
*/
#include <iostream>
#include <cctype>
#include <clocale>
int main()
{
    unsigned char c = '\x94'; // the control code CCH in ISO-8859-1
    std::cout << "iscntrl(\'\\x94\', default C locale) returned "
               << std::boolalpha << (bool)std::iscntrl(c) << '\n';
    std::setlocale(LC_ALL, "en_GB.iso88591");
    std::cout << "iscntrl(\'\\x94\', ISO-8859-1 locale) returned "
              << std::boolalpha << (bool)std::iscntrl(c) << '\n';
}

