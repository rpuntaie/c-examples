/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_substr.exe ./cpp/string_basic_string_view_substr.cpp && (cd ../_build/cpp/;./string_basic_string_view_substr.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/substr
*/
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string_view>
int main()
{
    using namespace std::literals;
    std::size_t count{}, pos{};
    constexpr auto data{"ABCDEF"sv};
    std::cout << data.substr() << '\n'; // ABCDEF
    std::cout << data.substr(pos = 1) << '\n'; // BCDEF
    std::cout << data.substr(pos = 2, count = 3) << '\n'; // CDE
    std::cout << data.substr(pos = 4, count = 42) << '\n'; // EF
        // count -> 2 == size() - pos == 6 - 4
    try {
        data.substr(pos = 666, count = 1); // throws: pos > size()
    }
    catch(std::out_of_range const& ex) {
        std::cout << ex.what() << '\n';
    }
}

