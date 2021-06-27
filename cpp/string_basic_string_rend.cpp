/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_rend.exe ./cpp/string_basic_string_rend.cpp && (cd ../_build/cpp/;./string_basic_string_rend.exe)
https://en.cppreference.com/w/cpp/string/basic_string/rend
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
int main()
{
  std::string s("A man, a plan, a canal: Panama");
  {
    std::string c;
    std::copy(s.rbegin(), s.rend(), std::back_inserter(c));
    std::cout << c <<'\n'; // "amanaP :lanac a ,nalp a ,nam A"
  }
  {
    std::string c;
    std::copy(s.crbegin(), s.crend(), std::back_inserter(c));
    std::cout << c <<'\n'; // "amanaP :lanac a ,nalp a ,nam A"
  }
}

