/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strncat.exe ./cpp/string_byte_strncat.cpp && (cd ../_build/cpp/;./string_byte_strncat.exe)
https://en.cppreference.com/w/cpp/string/byte/strncat
*/
#include <cstring>
#include <cstdio>
int main() 
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    std::strcat(str, str2);
    std::strncat(str, " Goodbye World!", 3);
    std::puts(str);
}

