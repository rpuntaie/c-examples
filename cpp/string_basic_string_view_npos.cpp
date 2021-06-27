/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_npos.exe ./cpp/string_basic_string_view_npos.cpp && (cd ../_build/cpp/;./string_basic_string_view_npos.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/npos
*/
#include <string_view>
constexpr bool
contains(std::string_view const what, std::string_view const where) noexcept {
    return std::string_view::npos != where.find(what);
}
int main()
{
    using namespace std::literals;
    static_assert(contains("water", "in a bottle of water"));
    static_assert(!contains("wine", "in a bottle of champagne"));
    static_assert(""sv.npos == "haystack"sv.find("needle"));
}

