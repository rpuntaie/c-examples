/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_from_chars.exe ./cpp/utility_from_chars.cpp && (cd ../_build/cpp/;./utility_from_chars.exe)
https://en.cppreference.com/w/cpp/utility/from_chars
*/
#include <array>
#include <charconv>
#include <iostream>
#include <string_view>
int main()
{
    std::array<char, 10> str{"42 xyz "};
    int result;
    if(auto [p, ec] = std::from_chars(str.data(), str.data()+str.size(), result);
       ec == std::errc())
        std::cout << result << "\n" "p -> \"" << p << "\"\n";
    std::string_view sv{"24 abc "};
    if(auto [p, ec] = std::from_chars(data(sv), data(sv)+size(sv), result);
       ec == std::errc())
        std::cout << result << "\n" "p -> \"" << p << "\"\n";
}

