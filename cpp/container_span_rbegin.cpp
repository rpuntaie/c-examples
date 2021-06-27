/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_span_rbegin.exe ./cpp/container_span_rbegin.cpp && (cd ../_build/cpp/;./container_span_rbegin.exe)
https://en.cppreference.com/w/cpp/container/span/rbegin
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <span>
int main()
{
    constexpr std::span<const char> code{ "@droNE_T0P_w$s@s#_SECRET_a,p^42!" };
    auto hacker = [](const unsigned O) { return O-0141<120; };
    std::copy_if(code.rbegin(), code.rend(),
        std::ostream_iterator<const char>(std::cout), hacker);
}

