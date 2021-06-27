/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_isprint.exe ./cpp/locale_isprint.cpp && (cd ../_build/cpp/;./locale_isprint.exe)
https://en.cppreference.com/w/cpp/locale/isprint
*/
#include <iostream>
#include <locale>
int main()
{
    const wchar_t c = L'\u2122'; // trademark sign
    std::locale loc1("C");
    std::cout << "isprint('™', C locale) returned "
               << std::boolalpha << std::isprint(c, loc1) << '\n';
    std::locale loc2("en_US.UTF-8");
    std::cout << "isprint('™', Unicode locale) returned "
              << std::boolalpha << std::isprint(c, loc2) << '\n';
}

