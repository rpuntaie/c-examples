/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_starts_with.exe ./cpp/string_basic_string_starts_with.cpp && (cd ../_build/cpp/;./string_basic_string_starts_with.exe)
https://en.cppreference.com/w/cpp/string/basic_string/starts_with
*/
#include <iostream>
#include <string_view>
#include <string>
template <typename PrefixType>
void test_prefix_print(const std::string& str, PrefixType prefix)
{
    std::cout << '\'' << str << "' starts with '" << prefix << "': " <<
        str.starts_with(prefix) << '\n';
}
int main()
{
    std::boolalpha(std::cout);    
    auto helloWorld = std::string("hello world");
    test_prefix_print(helloWorld, std::string_view("hello"));
    test_prefix_print(helloWorld, std::string_view("goodbye"));
    test_prefix_print(helloWorld, 'h');
    test_prefix_print(helloWorld, 'x');
}

