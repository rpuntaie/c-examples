/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_memchr.exe ./cpp/string_byte_memchr.cpp && (cd ../_build/cpp/;./string_byte_memchr.exe)
https://en.cppreference.com/w/cpp/string/byte/memchr
*/
#include <iostream>
#include <cstring>
int main()
{
    char arr[] = {'a','\0','a','A','a','a','A','a'};
    char *pc = (char*)std::memchr(arr,'A',sizeof arr);
    if (pc != nullptr)
       std::cout << "search character found\n";
    else
       std::cout << "search character not found\n";
}

