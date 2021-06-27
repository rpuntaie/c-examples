/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_swap.exe ./cpp/string_basic_string_swap.cpp && (cd ../_build/cpp/;./string_basic_string_swap.exe)
https://en.cppreference.com/w/cpp/string/basic_string/swap
*/
#include <string>
#include <iostream>
int main() 
{
    std::string a = "AAA";
    std::string b = "BBB";
    std::cout << "before swap" << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    a.swap(b);
    std::cout << "after swap" << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
}

