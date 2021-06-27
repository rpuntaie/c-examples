/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_span_empty.exe ./cpp/container_span_empty.cpp && (cd ../_build/cpp/;./container_span_empty.exe)
https://en.cppreference.com/w/cpp/container/span/empty
*/
#include <span>
#include <iostream>
#include <iomanip>
int main()
{
    std::span<const char> span{ "ABCDEF" };
    while (!span.empty()) {
        std::cout << std::quoted(span.data()) << '\n';
        span = span.last(span.size() - 1);
    }
}

