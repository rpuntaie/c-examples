/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_isalpha.exe ./cpp/locale_isalpha.cpp && (cd ../_build/cpp/;./locale_isalpha.exe)
https://en.cppreference.com/w/cpp/locale/isalpha
*/
#include <iostream>
#include <locale>
int main()
{
    const wchar_t c = L'\u042f'; // cyrillic capital letter ya
    std::locale loc1("C");
    std::cout << "isalpha('Я', C locale) returned "
               << std::boolalpha << std::isalpha(c, loc1) << '\n';
    std::locale loc2("en_US.UTF8");
    std::cout << "isalpha('Я', Unicode locale) returned "
              << std::boolalpha << std::isalpha(c, loc2) << '\n';
}

