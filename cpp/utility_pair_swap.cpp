/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_pair_swap.exe ./cpp/utility_pair_swap.cpp && (cd ../_build/cpp/;./utility_pair_swap.exe)
https://en.cppreference.com/w/cpp/utility/pair/swap
*/
#include <iostream>
#include <utility>
#include <string>
int main()
{
    std::pair<int, std::string> p1, p2;
    p1 = std::make_pair(10, "test");
    p2.swap(p1);
    std::cout << "(" << p2.first << ", " << p2.second << ")\n";
}

