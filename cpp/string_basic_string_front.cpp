/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_front.exe ./cpp/string_basic_string_front.cpp && (cd ../_build/cpp/;./string_basic_string_front.exe)
https://en.cppreference.com/w/cpp/string/basic_string/front
*/
#include <iostream>
#include <string>
int main()
{
  {
    std::string s("Exemplary");
    char& f = s.front();
    f = 'e';
    std::cout << s << '\n'; // "exemplary"
  }
  {
    std::string const c("Exemplary");
    char const& f = c.front();
    std::cout << &f << '\n'; // "Exemplary"
  }
}

