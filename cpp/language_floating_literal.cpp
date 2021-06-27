/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_floating_literal.exe ./cpp/language_floating_literal.cpp && (cd ../_build/cpp/;./language_floating_literal.exe)
https://en.cppreference.com/w/cpp/language/floating_literal
*/
#include <iostream>
int main()
{
  std::cout << 58.         << '\n'
            << 4e2         << '\n'
            << 123.456e-67 << '\n'
            << .1E4f       << '\n'
            << 0x10.1p0    << '\n'
            << 0x1e5       << '\n'; // integer literal, not floating point literal
}

