/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_data.exe ./cpp/string_basic_string_data.cpp && (cd ../_build/cpp/;./string_basic_string_data.exe)
https://en.cppreference.com/w/cpp/string/basic_string/data
*/
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>
int main()
{
  std::string const s("Emplary");
  assert(s.size() == std::strlen(s.data()));
  assert(std::equal(s.begin(), s.end(), s.data()));
  assert(std::equal(s.data(), s.data() + s.size(), s.begin()));
  assert(0 == *(s.data() + s.size()));
}

