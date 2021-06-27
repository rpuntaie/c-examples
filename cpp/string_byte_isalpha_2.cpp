/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_isalpha_2.exe ./cpp/string_byte_isalpha_2.cpp && (cd ../_build/cpp/;./string_byte_isalpha_2.exe)
https://en.cppreference.com/w/cpp/string/byte/isalpha
*/
#include <iostream>
#include <cctype> 
#include <clocale>
int main()
{        
    unsigned char c = '\xdf'; // German letter ß in ISO-8859-1
    std::cout << "isalpha(\'\\xdf\', default C locale) returned "
               << std::boolalpha << (bool)std::isalpha(c) << '\n';
    std::setlocale(LC_ALL, "de_DE.iso88591");
    std::cout << "isalpha(\'\\xdf\', ISO-8859-1 locale) returned "
              << std::boolalpha << (bool)std::isalpha(c) << '\n';
}

