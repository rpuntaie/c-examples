/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_ends_with.exe ./cpp/string_basic_string_ends_with.cpp && (cd ../_build/cpp/;./string_basic_string_ends_with.exe)
https://en.cppreference.com/w/cpp/string/basic_string/ends_with
*/
#include <iostream>
#include <string_view>
#include <string>
template <typename SuffixType>
void test_suffix_print(const std::string& str, SuffixType suffix)
{
    std::cout << '\'' << str << "' ends with '" << suffix << "': " <<
        str.ends_with(suffix) << '\n';
}
int main()
{
    std::boolalpha(std::cout);    
    auto helloWorld = std::string("hello world");
    test_suffix_print(helloWorld, std::string_view("world"));
    test_suffix_print(helloWorld, std::string_view("goodbye"));
    test_suffix_print(helloWorld, 'd');
    test_suffix_print(helloWorld, 'x');
}

