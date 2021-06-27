/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_rfind.exe ./cpp/string_basic_string_view_rfind.cpp && (cd ../_build/cpp/;./string_basic_string_view_rfind.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/rfind
*/
#include <string_view>
int main()
{
    using namespace std::literals;
    constexpr auto N = std::string_view::npos;
    static_assert(true
        && (6 == "AB AB AB"sv.rfind("AB"))
        && (6 == "AB AB AB"sv.rfind("ABCD", N, 2))
        && (3 == "AB AB AB"sv.rfind("AB", 5))
        && (2 == "B AB AB "sv.rfind("AB", 2))
        && (N == "B AB AB "sv.rfind("AB", 1))
        && (5 == "B AB AB "sv.rfind('A'))
        && (4 == "AB AB AB"sv.rfind('B', 4))
        && (N == "AB AB AB"sv.rfind('C'))
    );
}

