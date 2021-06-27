/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_strcmp.exe ./cpp/string_byte_strcmp.cpp && (cd ../_build/cpp/;./string_byte_strcmp.exe)
https://en.cppreference.com/w/cpp/string/byte/strcmp
*/
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
int main() 
{
    std::vector<const char*> cats {"Heathcliff", "Snagglepuss", "Hobbes", "Garfield"};
    std::sort(cats.begin(), cats.end(), [](const char *strA, const char *strB) {
        return std::strcmp(strA, strB) < 0;
    }); 
    for (const char *cat : cats) {
        std::cout << cat << '\n';
    }
}

