/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_char_traits.exe ./cpp/string_char_traits.cpp && (cd ../_build/cpp/;./string_char_traits.exe)
https://en.cppreference.com/w/cpp/string/char_traits
*/
#include <string>
#include <string_view>
#include <iostream>
#include <cctype>
struct ci_char_traits : public std::char_traits<char> {
    static char to_upper(char ch) {
        return std::toupper((unsigned char) ch);
    }
    static bool eq(char c1, char c2) {
         return to_upper(c1) == to_upper(c2);
     }
    static bool lt(char c1, char c2) {
         return to_upper(c1) <  to_upper(c2);
    }
    static int compare(const char* s1, const char* s2, std::size_t n) {
        while ( n-- != 0 ) {
            if ( to_upper(*s1) < to_upper(*s2) ) return -1;
            if ( to_upper(*s1) > to_upper(*s2) ) return 1;
            ++s1; ++s2;
        }
        return 0;
    }
    static const char* find(const char* s, std::size_t n, char a) {
        auto const ua (to_upper(a));
        while ( n-- != 0 ) 
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};
template<class DstTraits, class CharT, class SrcTraits>
constexpr std::basic_string_view<CharT, DstTraits>
    traits_cast(const std::basic_string_view<CharT, SrcTraits> src) noexcept
{
    return {src.data(), src.size()};
}
int main()
{
    using namespace std::literals;
    constexpr auto s1 = "Hello"sv;
    constexpr auto s2 = "heLLo"sv;
    if (traits_cast<ci_char_traits>(s1) == traits_cast<ci_char_traits>(s2))
        std::cout << s1 << " and " << s2 << " are equal\n";
}

