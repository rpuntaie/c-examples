/*
g++ --std=c++23 -pthread -o ../_build/cpp/string_basic_string_contains.exe ./cpp/string_basic_string_contains.cpp && (cd ../_build/cpp/;./string_basic_string_contains.exe)
https://en.cppreference.com/w/cpp/string/basic_string/contains
*/
#include <iostream>
#include <string_view>
#include <string>
template <typename SubstrType>
void test_substring_print(const std::string& str, SubstrType subs)
{
    std::cout << '\'' << str << "' contains '" << subs << "': " <<
        str.contains(subs) << '\n';
}
int main()
{
    std::boolalpha(std::cout);    
    auto helloWorld = std::string("hello world");
    test_substring_print(helloWorld, std::string_view("hello"));
    test_substring_print(helloWorld, std::string_view("goodbye"));
    test_substring_print(helloWorld, 'w');
    test_substring_print(helloWorld, 'x');
}

