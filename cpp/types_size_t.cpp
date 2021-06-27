/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_size_t.exe ./cpp/types_size_t.cpp && (cd ../_build/cpp/;./types_size_t.exe)
https://en.cppreference.com/w/cpp/types/size_t
*/
#include <cstddef>
#include <iostream>
#include <array>
int main()
{
    std::array<std::size_t,10> a;
    std::size_t i{};
    for (i = 0; i != a.size(); ++i)
        std::cout << (a[i] = i) << ' ';
    std::cout << "│ i = " << i << '\n';
    for (i = a.size()-1; i < a.size(); --i)
        std::cout << a[i] << ' ';
    std::cout << "│ i = " << i << '\n';
}

