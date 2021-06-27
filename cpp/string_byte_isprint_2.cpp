/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_isprint_2.exe ./cpp/string_byte_isprint_2.cpp && (cd ../_build/cpp/;./string_byte_isprint_2.exe)
https://en.cppreference.com/w/cpp/string/byte/isprint
*/
#include <iostream>
#include <cctype>
#include <clocale>
int main()
{
    unsigned char c = '\xa0'; // the non-breaking space in ISO-8859-1
    std::cout << "isprint(\'\\xa0\', default C locale) returned "
               << std::boolalpha << (bool)std::isprint(c) << '\n';
    std::setlocale(LC_ALL, "en_GB.iso88591");
    std::cout << "isprint(\'\\xa0\', ISO-8859-1 locale) returned "
              << std::boolalpha << (bool)std::isprint(c) << '\n';
}

