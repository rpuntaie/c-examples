/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_min_1.exe ./cpp/algorithm_ranges_min_1.cpp && (cd ../_build/cpp/;./algorithm_ranges_min_1.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/min
*/
#include <algorithm>
#include <iostream>
#include <string>
int main()
{
    namespace ranges = std::ranges;
    using namespace std::string_view_literals;
    std::cout << "smaller of 1 and 9999: " << ranges::min(1, 9999) << '\n'
              << "smaller of 'a', and 'b': '" << ranges::min('a', 'b') << "'\n"
              << "shortest of \"foo\", \"bar\", and \"hello\": \""
              << ranges::min({ "foo"sv, "bar"sv, "hello"sv }, {}, 
                             &std::string_view::size) << "\"\n";
}

