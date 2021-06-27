/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_min_1.exe ./cpp/algorithm_min_1.cpp && (cd ../_build/cpp/;./algorithm_min_1.exe)
https://en.cppreference.com/w/cpp/algorithm/min
*/
#include <algorithm>
#include <iostream>
#include <string_view>
int main()
{
    std::cout << "smaller of 1 and 9999 is " << std::min(1, 9999) << '\n'
              << "smaller of 'a', and 'b' is '" << std::min('a', 'b') << "'\n"
              << "shortest of \"foo\", \"bar\", and \"hello\" is \""
              << std::min({ "foo", "bar", "hello" },
                          [](const std::string_view s1, const std::string_view s2) {
                              return s1.size() < s2.size();
                          }) << "\"\n";
}

