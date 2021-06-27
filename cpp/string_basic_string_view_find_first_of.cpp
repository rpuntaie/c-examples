/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_find_first_of.exe ./cpp/string_basic_string_view_find_first_of.cpp && (cd ../_build/cpp/;./string_basic_string_view_find_first_of.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/find_first_of
*/
#include <string_view>
#include <iostream>
int main()
{
    using namespace std::literals;
    constexpr auto N = std::string_view::npos;
    auto is_white_space = [](const char c) noexcept {
        return " \t\n\f\r\v"sv.find_first_of(c) != N;
    };
    static_assert(
        1 == "alignas"sv.find_first_of("klmn"sv) &&
          //   └─────────────────────────┘
        N == "alignof"sv.find_first_of("wxyz"sv) &&
          //
        3 == "concept"sv.find_first_of("bcde"sv, /* pos= */ 1) &&
          //     └───────────────────────┘
        N == "consteval"sv.find_first_of("oxyz"sv, /* pos= */ 2) &&
          //
        6 == "constexpr"sv.find_first_of('x') &&
          //        └─────────────────────┘
        N == "constinit"sv.find_first_of('x') &&
          //
        6 == "const_cast"sv.find_first_of('c', /* pos= */ 4) &&
          //        └──────────────────────┘
        N == "continue"sv.find_first_of('c', /* pos= */ 42) &&
          //
        5 == "co_await"sv.find_first_of("cba", /* pos= */ 4) &&
          //       └───────────────────────┘
        7 == "decltype"sv.find_first_of("def", /* pos= */ 2, /* count= */ 2) &&
          //         └────────────────────┘
        N == "decltype"sv.find_first_of("def", /* pos= */ 2, /* count= */ 1) &&
          //
        is_white_space(' ') && is_white_space('\r') && !is_white_space('\a')
    );
    std::cout << "All tests passed.\n";
}

