/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_islower.exe ./cpp/locale_islower.cpp && (cd ../_build/cpp/;./locale_islower.exe)
https://en.cppreference.com/w/cpp/locale/islower
*/
#include <iostream>
#include <locale>
int main()
{
    const wchar_t c = L'\u03c0'; // greek small letter pi
    std::locale loc1("C");
    std::cout << "islower('π', C locale) returned "
               << std::boolalpha << std::islower(c, loc1) << '\n';
    std::locale loc2("en_US.UTF8");
    std::cout << "islower('π', Unicode locale) returned "
              << std::boolalpha << std::islower(c, loc2) << '\n';
}

