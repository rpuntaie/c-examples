/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strrchr.exe ./cpp/string_byte_strrchr.cpp && (cd ../_build/cpp/;./string_byte_strrchr.exe)
https://en.cppreference.com/w/cpp/string/byte/strrchr
*/
#include <iostream>
#include <cstring>
int main()
{
    char input[] = "/home/user/hello.c";
    char* output = std::strrchr(input, '/');
    if(output)
        std::cout << output+1 << '\n';
}

