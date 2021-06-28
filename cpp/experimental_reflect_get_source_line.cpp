/*
# g++ --std=c++20 -pthread -o ../_build/cpp/experimental_reflect_get_source_line.exe ./cpp/experimental_reflect_get_source_line.cpp && (cd ../_build/cpp/;./experimental_reflect_get_source_line.exe)
https://en.cppreference.com/w/cpp/experimental/reflect/get_source_line
*/
#include<experimental/reflect>
#include<iostream>
using refl = std::experimental::reflect;
float f;
struct P{};
int main()
{
    std::cout << refl::get_source_line_v<reflexpr(f)> << '\n';
    std::cout << refl::get_source_line_v<reflexpr(P)> << '\n';
}

