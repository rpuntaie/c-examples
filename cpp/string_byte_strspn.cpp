/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strspn.exe ./cpp/string_byte_strspn.cpp && (cd ../_build/cpp/;./string_byte_strspn.exe)
https://en.cppreference.com/w/cpp/string/byte/strspn
*/
#include <cstring>
#include <string>
#include <iostream>
const char *low_alpha = "qwertyuiopasdfghjklzxcvbnm";
int main()
{
    std::string s = "abcde312$#@";
    std::size_t spnsz = std::strspn(s.c_str(), low_alpha);
    std::cout << "After skipping initial lowercase letters from '" << s
              << "'\nThe remainder is '" << s.substr(spnsz) << "'\n";
}

