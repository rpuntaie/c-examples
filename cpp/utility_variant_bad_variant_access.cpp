/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_bad_variant_access.exe ./cpp/utility_variant_bad_variant_access.cpp && (cd ../_build/cpp/;./utility_variant_bad_variant_access.exe)
https://en.cppreference.com/w/cpp/utility/variant/bad_variant_access
*/
#include <variant>
#include <iostream>
int main()
{
    std::variant<int, float> v;
    v = 12;
    try {
      std::get<float>(v);
    }
    catch(const std::bad_variant_access& e) {
        std::cout << e.what() << '\n';
    }
}

