/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_holds_alternative.exe ./cpp/utility_variant_holds_alternative.cpp && (cd ../_build/cpp/;./utility_variant_holds_alternative.exe)
https://en.cppreference.com/w/cpp/utility/variant/holds_alternative
*/
#include <variant>
#include <string>
#include <iostream>
int main()
{
    std::variant<int, std::string> v = "abc";
    std::cout << std::boolalpha
              << "variant holds int? "
              << std::holds_alternative<int>(v) << '\n'
              << "variant holds string? "
              << std::holds_alternative<std::string>(v) << '\n';
}

