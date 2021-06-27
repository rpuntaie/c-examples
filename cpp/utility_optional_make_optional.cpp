/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_optional_make_optional.exe ./cpp/utility_optional_make_optional.cpp && (cd ../_build/cpp/;./utility_optional_make_optional.exe)
https://en.cppreference.com/w/cpp/utility/optional/make_optional
*/
#include <optional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <initializer_list>
int main()
{
    auto op1=std::make_optional<std::vector<char>>({'a','b','c'});
    std::cout<<"op1: ";
    for (char c: op1.value()){
        std::cout<<c<<",";
    }
    auto op2=std::make_optional<std::vector<int>>(5, 2);
    std::cout<<"\nop2: ";
    for (int i: *op2){
        std::cout<<i<<",";
    }
    std::string str{"hello world"};
    auto op3=std::make_optional<std::string>(std::move(str));
    std::cout<<"\nop3: "<<quoted(op3?*op3:"empty value")<<'\n';
    std::cout<<"str: "<<std::quoted(str)<<'\n';
}

