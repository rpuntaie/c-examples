/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_isupper_2.exe ./cpp/string_byte_isupper_2.cpp && (cd ../_build/cpp/;./string_byte_isupper_2.exe)
https://en.cppreference.com/w/cpp/string/byte/isupper
*/
#include <iostream>
#include <cctype>
#include <clocale>
int main()
{
    unsigned char c = '\xc6'; // letter Æ in ISO-8859-1
    std::cout << "isupper(\'\\xc6\', default C locale) returned "
               << std::boolalpha << (bool)std::isupper(c) << '\n';
    std::setlocale(LC_ALL, "en_GB.iso88591");
    std::cout << "isupper(\'\\xc6\', ISO-8859-1 locale) returned "
              << std::boolalpha << (bool)std::isupper(c) << '\n';
}

