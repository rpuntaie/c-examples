/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strtok.exe ./cpp/string_byte_strtok.cpp && (cd ../_build/cpp/;./string_byte_strtok.exe)
https://en.cppreference.com/w/cpp/string/byte/strtok
*/
#include <cstring>
#include <iostream>
int main() 
{
    char input[100] = "A bird came down the walk";
    char *token = std::strtok(input, " ");
    while (token) {
        std::cout << token << '\n';
        token = std::strtok(nullptr, " ");
    }
}

