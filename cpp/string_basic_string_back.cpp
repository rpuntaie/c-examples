/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_back.exe ./cpp/string_basic_string_back.cpp && (cd ../_build/cpp/;./string_basic_string_back.exe)
https://en.cppreference.com/w/cpp/string/basic_string/back
*/
#include <iostream>
#include <string>
int main()
{
  {
    std::string s("Exemplary");
    char& back = s.back();
    back = 's';
    std::cout << s << '\n'; // "Exemplars"
  }
  {
    std::string const c("Exemplary");
    char const& back = c.back();
    std::cout << back << '\n'; // 'y'
  }
}

