/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_character_literal.exe ./cpp/language_character_literal.cpp && (cd ../_build/cpp/;./language_character_literal.exe)
https://en.cppreference.com/w/cpp/language/character_literal
*/
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string_view>
template <typename CharT>
void dump(std::string_view s, const CharT c) {
    const uint8_t* data {reinterpret_cast<const uint8_t*>(&c)};
    std::cout << "'" << s << "' \t" << std::hex
              << std::uppercase << std::setfill('0');
    for (auto i {0U}; i != sizeof(CharT); ++i){
        std::cout << std::setw(2) << static_cast<unsigned>(data[i]) << ' ';
    }
    std::cout << '\n';
}
void print(std::string_view str) { std::cout << str; }
int main()
{
    print("literal hex dump \n"
          "─────── ───────────\n");
    dump("a", 'a');
    dump("🍌", '🍌'); // implementation-defined
    print("\n");
    // ordinary multi-character literal
    dump("ab", 'ab'); // implementation-defined
    print("\n");
    // UTF-16 character literals
    char16_t uc1 = u'a'; dump("a", uc1);
    char16_t uc2 = u'¢'; dump("¢", uc2);
    char16_t uc3 = u'猫'; dump("猫", uc3);
//  char16_t uc4 = u'🍌'; dump("🍌", uc4); // error: 🍌 maps to two UTF-16 code units
    print("\n");
    // UTF-32 character literals
    char32_t Uc1 = U'a'; dump("a", Uc1);
    char32_t Uc2 = U'¢'; dump("¢", Uc2);
    char32_t Uc3 = U'猫'; dump("猫", Uc3);
    char32_t Uc4 = U'🍌'; dump("🍌", Uc4);
    print("\n");
    // wide character literals
    wchar_t wc1 = L'a'; dump("a", wc1);
    wchar_t wc2 = L'¢'; dump("¢", wc2);
    wchar_t wc3 = L'猫'; dump("猫", wc3);
    wchar_t wc4 = L'🍌'; dump("🍌", wc4);
}

