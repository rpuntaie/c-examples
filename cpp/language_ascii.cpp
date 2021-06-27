/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_ascii.exe ./cpp/language_ascii.cpp && (cd ../_build/cpp/;./language_ascii.exe)
https://en.cppreference.com/w/cpp/language/ascii
*/
#include <iostream>
int main()
{
  std::cout << "Printable ASCII [32..126]:\n";
  for (char i = ' '; i <= '~'; ++i) {
    std::cout << i << ((i % 16 == 15) ? '\n' : ' ');
  }
}

