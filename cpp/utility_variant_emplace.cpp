/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_emplace.exe ./cpp/utility_variant_emplace.cpp && (cd ../_build/cpp/;./utility_variant_emplace.exe)
https://en.cppreference.com/w/cpp/utility/variant/emplace
*/
#include <iostream>
#include <string>
#include <variant>
int main()
{
    std::variant<std::string> v1;
    v1.emplace<0>("abc"); // OK
    std::cout << std::get<0>(v1) << '\n';
    v1.emplace<std::string>("def"); // OK
    std::cout << std::get<0>(v1) << '\n';
    std::variant<std::string, std::string> v2;
    v2.emplace<1>("ghi"); // OK
    std::cout << std::get<1>(v2) << '\n';
    // v2.emplace<std::string>("abc"); -> Error
}

