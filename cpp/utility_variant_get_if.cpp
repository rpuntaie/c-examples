/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_get_if.exe ./cpp/utility_variant_get_if.cpp && (cd ../_build/cpp/;./utility_variant_get_if.exe)
https://en.cppreference.com/w/cpp/utility/variant/get_if
*/
#include <variant>
#include <iostream>
int main()
{
    std::variant<int, float> v{12};
    if(auto pval = std::get_if<int>(&v))
      std::cout << "variant value: " << *pval << '\n'; 
    else 
      std::cout << "failed to get value!" << '\n'; 
}

