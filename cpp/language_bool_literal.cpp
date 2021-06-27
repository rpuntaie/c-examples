/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_bool_literal.exe ./cpp/language_bool_literal.cpp && (cd ../_build/cpp/;./language_bool_literal.exe)
https://en.cppreference.com/w/cpp/language/bool_literal
*/
#include <iostream>
int main()
{
  std::cout << std::boolalpha
            << true << '\n'
            << false << '\n'
            << std::noboolalpha
            << true << '\n'
            << false << '\n';
}

