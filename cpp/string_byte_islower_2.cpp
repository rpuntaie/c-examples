/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_islower_2.exe ./cpp/string_byte_islower_2.cpp && (cd ../_build/cpp/;./string_byte_islower_2.exe)
https://en.cppreference.com/w/cpp/string/byte/islower
*/
#include <iostream>
#include <cctype>
#include <clocale>
int main()
{
    unsigned char c = '\xe5'; // letter å in ISO-8859-1
    std::cout << "islower(\'\\xe5\', default C locale) returned "
               << std::boolalpha << (bool)std::islower(c) << '\n';
    std::setlocale(LC_ALL, "en_GB.iso88591");
    std::cout << "islower(\'\\xe5\', ISO-8859-1 locale) returned "
              << std::boolalpha << (bool)std::islower(c) << '\n';
}

