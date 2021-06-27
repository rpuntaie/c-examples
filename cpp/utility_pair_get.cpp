/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_pair_get.exe ./cpp/utility_pair_get.cpp && (cd ../_build/cpp/;./utility_pair_get.exe)
https://en.cppreference.com/w/cpp/utility/pair/get
*/
#include <iostream>
#include <utility>
int main()
{
    auto p = std::make_pair(1, 3.14);
    std::cout << '(' << std::get<0>(p) << ", " << std::get<1>(p) << ")\n";
    std::cout << '(' << std::get<int>(p) << ", " << std::get<double>(p) << ")\n";
}

