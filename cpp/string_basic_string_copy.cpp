/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_copy.exe ./cpp/string_basic_string_copy.cpp && (cd ../_build/cpp/;./string_basic_string_copy.exe)
https://en.cppreference.com/w/cpp/string/basic_string/copy
*/
#include <string>
#include <iostream>
int main()
{
  std::string foo("quuuux");
  char bar[7]{};
  foo.copy(bar, sizeof bar);
  std::cout << bar << '\n';
}

