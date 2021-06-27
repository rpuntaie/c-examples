/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strcoll.exe ./cpp/string_byte_strcoll.cpp && (cd ../_build/cpp/;./string_byte_strcoll.exe) || true
https://en.cppreference.com/w/cpp/string/byte/strcoll
*/
#include <iostream>
#include <cstring>
#include <clocale>
int main()
{
    std::setlocale(LC_COLLATE, "cs_CZ.iso88592");
    const char* s1 = "hrnec";
    const char* s2 = "chrt";
    std::cout << "In the Czech locale: ";
    if(std::strcoll(s1, s2) < 0)
         std::cout << s1 << " before " << s2 << '\n';
    else
         std::cout << s2 << " before " << s1 << '\n';
    std::cout << "In lexicographical comparison: ";
    if(std::strcmp(s1, s2) < 0)
         std::cout << s1 << " before " << s2 << '\n';
    else
         std::cout << s2 << " before " << s1 << '\n';
}

