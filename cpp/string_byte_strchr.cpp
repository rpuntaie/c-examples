/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strchr.exe ./cpp/string_byte_strchr.cpp && (cd ../_build/cpp/;./string_byte_strchr.exe)
https://en.cppreference.com/w/cpp/string/byte/strchr
*/
#include <iostream>
#include <cstring>
int main()
{
  const char *str = "Try not. Do, or do not. There is no try.";
  char target = 'T';
  const char *result = str;
  while ((result = std::strchr(result, target)) != nullptr) {
    std::cout << "Found '" << target
              << "' starting at '" << result << "'\n";
    // Increment result, otherwise we'll find target at the same location
    ++result;
  }
}

