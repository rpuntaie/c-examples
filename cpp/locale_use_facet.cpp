/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_use_facet.exe ./cpp/locale_use_facet.cpp && (cd ../_build/cpp/;./locale_use_facet.exe)
https://en.cppreference.com/w/cpp/locale/use_facet
*/
#include <iostream>
#include <locale>
int main()
{
    std::locale loc = std::locale(""); // user's preferred locale
    std::cout << "Your currency string is "
              << std::use_facet<std::moneypunct<char, true>>(loc).curr_symbol() << '\n';
}

