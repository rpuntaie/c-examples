/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_byte_atoi.exe ./cpp/string_byte_atoi.cpp && (cd ../_build/cpp/;./string_byte_atoi.exe)
https://en.cppreference.com/w/cpp/string/byte/atoi
*/
#include <iostream>
#include <cstdlib>
int main()
{
    const char *str1 = "42";
    const char *str2 = "3.14159";
    const char *str3 = "31337 with words";
    const char *str4 = "words and 2";
    int num1 = std::atoi(str1);
    int num2 = std::atoi(str2);
    int num3 = std::atoi(str3);
    int num4 = std::atoi(str4);
    std::cout << "std::atoi(\"" << str1 << "\") is " << num1 << '\n';
    std::cout << "std::atoi(\"" << str2 << "\") is " << num2 << '\n';
    std::cout << "std::atoi(\"" << str3 << "\") is " << num3 << '\n';
    std::cout << "std::atoi(\"" << str4 << "\") is " << num4 << '\n';
}

