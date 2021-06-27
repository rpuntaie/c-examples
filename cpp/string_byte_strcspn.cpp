/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strcspn.exe ./cpp/string_byte_strcspn.cpp && (cd ../_build/cpp/;./string_byte_strcspn.exe)
https://en.cppreference.com/w/cpp/string/byte/strcspn
*/
#include <string>
#include <cstring>
#include <iostream>
const char* invalid = "*$#";
int main()
{
    std::string s = "abcde312$#@";
    size_t valid_len = std::strcspn(s.c_str(), invalid);
    if(valid_len != s.size())
       std::cout << "'" << s << "' contains invalid chars starting at position "
                 << valid_len << '\n';
}

