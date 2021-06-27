/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_max_1.exe ./cpp/algorithm_max_1.cpp && (cd ../_build/cpp/;./algorithm_max_1.exe)
https://en.cppreference.com/w/cpp/algorithm/max
*/
#include <algorithm>
#include <iostream>
#include <string_view>
int main()
{
    std::cout << "larger of 1 and 9999 is " << std::max(1, 9999) << '\n'
              << "larger of 'a', and 'b' is '" << std::max('a', 'b') << "'\n"
              << "largest of 1, 10, 50, and 200 is " << std::max({1, 10, 50, 200}) << '\n'
              << "longest of \"foo\", \"bar\", and \"hello\" is \""
              << std::max({ "foo", "bar", "hello" },
                          [](const std::string_view s1, const std::string_view s2) {
                              return s1.size() < s2.size();
                          }) << "\"\n";
}

