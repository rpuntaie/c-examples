/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strpbrk.exe ./cpp/string_byte_strpbrk.cpp && (cd ../_build/cpp/;./string_byte_strpbrk.exe)
https://en.cppreference.com/w/cpp/string/byte/strpbrk
*/
#include <iostream>
#include <cstring>
#include <iomanip>
int main()
{
    const char* str = "hello world, friend of mine!";
    const char* sep = " ,!";
    unsigned int cnt = 0;
    do {
       str = std::strpbrk(str, sep); // find separator
       std::cout << std::quoted(str) << '\n';
       if(str) str += std::strspn(str, sep); // skip separator
       ++cnt; // increment word count
    } while(str && *str);
    std::cout << "There are " << cnt << " words\n";
}

