/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_remove_cvref.exe ./cpp/types_remove_cvref.cpp && (cd ../_build/cpp/;./types_remove_cvref.exe)
https://en.cppreference.com/w/cpp/types/remove_cvref
*/
#include <iostream>
#include <type_traits>
int main()
{
    std::cout << std::boolalpha
              << std::is_same_v<std::remove_cvref_t<int>, int> << '\n'
              << std::is_same_v<std::remove_cvref_t<int&>, int> << '\n'
              << std::is_same_v<std::remove_cvref_t<int&&>, int> << '\n'
              << std::is_same_v<std::remove_cvref_t<const int&>, int> << '\n'
              << std::is_same_v<std::remove_cvref_t<const int[2]>, int[2]> << '\n'
              << std::is_same_v<std::remove_cvref_t<const int(&)[2]>, int[2]> << '\n'
              << std::is_same_v<std::remove_cvref_t<int(int)>, int(int)> << '\n';
}

