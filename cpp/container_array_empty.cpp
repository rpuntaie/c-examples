/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_empty.exe ./cpp/container_array_empty.cpp && (cd ../_build/cpp/;./container_array_empty.exe)
https://en.cppreference.com/w/cpp/container/array/empty
*/
#include <array>
#include <iostream>
int main()
{
    std::array<int, 4> numbers {3, 1, 4, 1};
    std::array<int, 0> no_numbers;
    std::cout << std::boolalpha;
    std::cout << "numbers.empty(): " << numbers.empty() << '\n';
    std::cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';
}

