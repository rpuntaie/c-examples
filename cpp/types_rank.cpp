/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_rank.exe ./cpp/types_rank.cpp && (cd ../_build/cpp/;./types_rank.exe)
https://en.cppreference.com/w/cpp/types/rank
*/
#include <iostream>
#include <type_traits>
int main()
{
    std::cout << std::rank<int>{} << "\n\n";
    std::cout << std::rank<int[5]>{} << '\n';
    std::cout << std::rank<int[5][5]>{} << '\n';
    std::cout << std::rank<int[][5][5]>{} << '\n';
}

