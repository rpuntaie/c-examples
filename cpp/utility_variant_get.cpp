/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_get.exe ./cpp/utility_variant_get.cpp && (cd ../_build/cpp/;./utility_variant_get.exe)
https://en.cppreference.com/w/cpp/utility/variant/get
*/
#include <variant>
#include <string>
#include <iostream>
int main()
{
    std::variant<int, float> v{12}, w;
    std::cout << std::get<int>(v) << '\n';
    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line
//  std::get<double>(v); // error: no double in [int, float]
//  std::get<3>(v);      // error: valid index values are 0 and 1
    try
    {
        w = 42.0f;
        std::cout << std::get<float>(w) << '\n'; // ok, prints 42
        w = 42;
        std::cout << std::get<float>(w) << '\n'; // throws
    }
    catch (std::bad_variant_access const& ex)
    {
        std::cout << ex.what() << ": w contained int, not float\n";
    }
}

