/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strlen.exe ./cpp/string_byte_strlen.cpp && (cd ../_build/cpp/;./string_byte_strlen.exe)
https://en.cppreference.com/w/cpp/string/byte/strlen
*/
#include <cstring>
#include <iostream>
int main()
{
   const char str[] = "How many characters does this string contain?";
   std::cout << "without null character: " << std::strlen(str) << '\n'
             << "with null character: " << sizeof str << '\n';
}

