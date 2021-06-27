/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_operatorsv.exe ./cpp/string_basic_string_view_operatorsv.cpp && (cd ../_build/cpp/;./string_basic_string_view_operatorsv.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/operator""sv
*/
#include <string_view>
#include <iostream>
#include <typeinfo>
int main()
{
    using namespace std::literals;
    std::string_view s1 = "abc\0\0def";
    std::string_view s2 = "abc\0\0def"sv;
    std::cout << "s1: " << s1.size() << ' ' << s1 << '\n'
              << "s2: " << s2.size() << ' ' << s2 << '\n'
              << "abcdef"sv.substr(1,4) << '\n';
    auto value_type_info = []<typename T>(T) {
        using V = typename T::value_type;
        std::cout << "sizeof " << typeid(V).name()
                  << ": " << sizeof(V) << '\n';
    };
    value_type_info( "char A"sv      );
    value_type_info( L"wchar_t ∀"sv  );
    value_type_info( u8"char8_t ∆"sv );
    value_type_info( u"char16_t ∇"sv );
    value_type_info( U"char32_t ∃"sv );
    value_type_info( LR"(raw ⊞)"sv  );
}

