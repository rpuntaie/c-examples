/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_span_data.exe ./cpp/container_span_data.cpp && (cd ../_build/cpp/;./container_span_data.exe)
https://en.cppreference.com/w/cpp/container/span/data
*/
#include <span>
#include <iostream>
int main()
{
    constexpr char str[] = "ABCDEF\n";
    const std::span sp{str};
    for (auto n{sp.size()}; n != 2; --n) {
        std::cout << sp.last(n).data();
    }
}

