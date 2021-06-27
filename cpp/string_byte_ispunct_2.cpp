/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_ispunct_2.exe ./cpp/string_byte_ispunct_2.cpp && (cd ../_build/cpp/;./string_byte_ispunct_2.exe)
https://en.cppreference.com/w/cpp/string/byte/ispunct
*/
#include <iostream>
#include <cctype>
#include <clocale>
int main()
{
    unsigned char c = '\xd7'; // the character × (multiplication sign) in ISO-8859-1
    std::cout << "ispunct(\'\\xd7\', default C locale) returned "
               << std::boolalpha << (bool)std::ispunct(c) << '\n';
    std::setlocale(LC_ALL, "en_GB.iso88591");
    std::cout << "ispunct(\'\\xd7\', ISO-8859-1 locale) returned "
              << std::boolalpha << (bool)std::ispunct(c) << '\n';
}

