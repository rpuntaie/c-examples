/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_max_1.exe ./cpp/algorithm_ranges_max_1.cpp && (cd ../_build/cpp/;./algorithm_ranges_max_1.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/max
*/
#include <algorithm>
#include <iostream>
#include <string>
int main()
{
    namespace ranges = std::ranges;
    using namespace std::string_view_literals;
    std::cout << "larger of 1 and 9999: " << ranges::max(1, 9999) << '\n'
              << "larger of 'a', and 'b': '" << ranges::max('a', 'b') << "'\n"
              << "longest of \"foo\", \"bar\", and \"hello\": \""
              << ranges::max({ "foo"sv, "bar"sv, "hello"sv }, {}, 
                             &std::string_view::size) << "\"\n";
}

