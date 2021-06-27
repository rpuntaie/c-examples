/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_find_last_not_of.exe ./cpp/string_basic_string_view_find_last_not_of.cpp && (cd ../_build/cpp/;./string_basic_string_view_find_last_not_of.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/find_last_not_of
*/
#include <string_view>
using std::operator""sv;
int main()
{
    static_assert(1 == "BCDEF"sv.find_last_not_of("DEF"));
                    //   ^
    static_assert(2 == "BCDEFG"sv.find_last_not_of("EFG", 3));
                    //    ^
    static_assert(2 == "ABBA"sv.find_last_not_of('A'));
                    //    ^
    static_assert(1 == "ABBA"sv.find_last_not_of('A', 1));
                    //   ^
}

