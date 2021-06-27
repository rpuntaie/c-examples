/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_index.exe ./cpp/utility_variant_index.cpp && (cd ../_build/cpp/;./utility_variant_index.exe)
https://en.cppreference.com/w/cpp/utility/variant/index
*/
#include <variant>
#include <string>
#include <iostream>
int main()
{
    std::variant<int, std::string> v = "abc";
    std::cout << "v.index = " << v.index() << '\n';
    v = {}; 
    std::cout << "v.index = " << v.index() << '\n';
}

