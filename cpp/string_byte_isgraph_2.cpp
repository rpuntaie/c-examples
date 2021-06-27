/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_isgraph_2.exe ./cpp/string_byte_isgraph_2.cpp && (cd ../_build/cpp/;./string_byte_isgraph_2.exe)
https://en.cppreference.com/w/cpp/string/byte/isgraph
*/
#include <iostream>
#include <cctype>
#include <clocale>
int main()
{
    unsigned char c = '\xb6'; // the character ¶ in ISO-8859-1
    std::cout << "isgraph(\'\\xb6\', default C locale) returned "
               << std::boolalpha << (bool)std::isgraph(c) << '\n';
    std::setlocale(LC_ALL, "en_GB.iso88591");
    std::cout << "isgraph(\'\\xb6\', ISO-8859-1 locale) returned "
              << std::boolalpha << (bool)std::isgraph(c) << '\n';
}

