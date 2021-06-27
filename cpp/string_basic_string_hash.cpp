/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_hash.exe ./cpp/string_basic_string_hash.cpp && (cd ../_build/cpp/;./string_basic_string_hash.exe)
https://en.cppreference.com/w/cpp/string/basic_string/hash
*/
#include <iostream>
#include <string>
#include <string_view>
#include <functional>
#include <memory_resource>
using namespace std::literals;
int main()
{
    auto sv = "Stand back! I've got jimmies!"sv;
    std::string s(sv);
    std::pmr::string pmrs(sv); // use default allocator
    std::cout << std::hash<std::string_view>{}(sv) << '\n';
    std::cout << std::hash<std::string>{}(s) << '\n';
    std::cout << std::hash<std::pmr::string>{}(pmrs) << '\n';
}

