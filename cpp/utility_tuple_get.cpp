/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_tuple_get.exe ./cpp/utility_tuple_get.cpp && (cd ../_build/cpp/;./utility_tuple_get.exe)
https://en.cppreference.com/w/cpp/utility/tuple/get
*/
#include <iostream>
#include <string>
#include <tuple>
int main()
{
    auto t = std::make_tuple(1, "Foo", 3.14);
    // index-based access
    std::cout << "(" << std::get<0>(t) << ", " << std::get<1>(t)
              << ", " << std::get<2>(t) << ")\n";
    // type-based access (C++14 or later)
    std::cout << "(" << std::get<int>(t) << ", " << std::get<const char*>(t)
              << ", " << std::get<double>(t) << ")\n";
    // Note: std::tie and structured binding may also be used to decompose a tuple
}

