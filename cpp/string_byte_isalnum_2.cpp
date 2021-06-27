/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_isalnum_2.exe ./cpp/string_byte_isalnum_2.cpp && (cd ../_build/cpp/;./string_byte_isalnum_2.exe)
https://en.cppreference.com/w/cpp/string/byte/isalnum
*/
#include <iostream>
#include <cctype>
#include <clocale>
int main()
{
    unsigned char c = '\xdf'; // German letter ß in ISO-8859-1
    std::cout << "isalnum(\'\\xdf\', default C locale) returned "
               << std::boolalpha << (bool)std::isalnum(c) << '\n';
    if(std::setlocale(LC_ALL, "de_DE.iso88591"))
        std::cout << "isalnum(\'\\xdf\', ISO-8859-1 locale) returned "
                  << std::boolalpha << (bool)std::isalnum(c) << '\n';
}

