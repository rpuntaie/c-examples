/*
# g++ --std=c++20 -pthread -o ../_build/cpp/utility_format_format_to_n.exe ./cpp/utility_format_format_to_n.cpp && (cd ../_build/cpp/;./utility_format_format_to_n.exe)
https://en.cppreference.com/w/cpp/utility/format/format_to_n
*/
#include <format>
#include <string_view>
#include <iostream>
int main()
{
    char buffer[64];
    const auto result =
        std::format_to_n(buffer, std::size(buffer), 
                         "Hubble's H{0} {1} {2} km/sec/mpc.",
                         "\u2080", "\u2245", 71);
    std::cout << "Buffer: \"" << std::string_view{buffer, result.size} << "\"\n"
              << "Buffer size = " << std::size(buffer) << '\n'
              << "Untruncated output size = " << result.size << '\n';
}

