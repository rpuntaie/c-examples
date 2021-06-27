/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_c_str.exe ./cpp/string_basic_string_c_str.cpp && (cd ../_build/cpp/;./string_basic_string_c_str.exe)
https://en.cppreference.com/w/cpp/string/basic_string/c_str
*/
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>
int main()
{
  std::string const s("Emplary");
  assert(s.size() == std::strlen(s.c_str()));
  assert(std::equal(s.begin(), s.end(), s.c_str()));
  assert(std::equal(s.c_str(), s.c_str() + s.size(), s.begin()));
  assert(0 == *(s.c_str() + s.size()));
}

