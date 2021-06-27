/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_string_literal_4.exe ./cpp/language_string_literal_4.cpp && (cd ../_build/cpp/;./language_string_literal_4.exe)
https://en.cppreference.com/w/cpp/language/string_literal
*/
#include <iostream>
char array1[] = "Foo" "bar";
// same as
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
const char* s1 = R"foo(
Hello
  World
)foo";
// same as
const char* s2 = "\nHello\n  World\n";
// same as
const char* s3 = "\n"
                 "Hello\n"
                 "  World\n";
const wchar_t* s4 = L"ABC" L"DEF"; // ok, same as
const wchar_t* s5 = L"ABCDEF";
const char32_t* s6 = U"GHI" "JKL"; // ok, same as
const char32_t* s7 = U"GHIJKL";
const char16_t* s9 = "MN" u"OP" "QR"; // ok, same as
const char16_t* sA = u"MNOPQR";
// const auto* sB = u"Mixed" U"Types";
        // before C++23 may or may not be supported by
        // the implementation; ill-formed since C++23
const wchar_t* sC = LR"--(STUV)--"; // ok, raw string literal
int main()
{
    std::cout << array1 << ' ' << array2 << '\n'
              << s1 << s2 << s3 << std::endl;
    std::wcout << s4 << ' ' << s5 << ' ' << sC
               << std::endl;
}

