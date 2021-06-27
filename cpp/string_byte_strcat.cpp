/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strcat.exe ./cpp/string_byte_strcat.cpp && (cd ../_build/cpp/;./string_byte_strcat.exe)
https://en.cppreference.com/w/cpp/string/byte/strcat
*/
#include <cstring>
#include <cstdio>
int main() 
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    std::strcat(str, str2);
    std::strcat(str, " Goodbye World!");
    std::puts(str);
}

