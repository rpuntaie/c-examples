/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_isgraph.exe ./cpp/locale_isgraph.cpp && (cd ../_build/cpp/;./locale_isgraph.exe)
https://en.cppreference.com/w/cpp/locale/isgraph
*/
#include <iostream>
#include <locale>
int main()
{
    const wchar_t c = L'\u2a0c'; // quadruple integral
    std::locale loc1("C");
    std::cout << "isgraph('⨌', C locale) returned "
               << std::boolalpha << std::isgraph(c, loc1) << '\n';
    std::locale loc2("en_US.UTF-8");
    std::cout << "isgraph('⨌', Unicode locale) returned "
              << std::boolalpha << std::isgraph(c, loc2) << '\n';
}

