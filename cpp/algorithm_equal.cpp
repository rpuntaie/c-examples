/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_equal.exe ./cpp/algorithm_equal.cpp && (cd ../_build/cpp/;./algorithm_equal.exe)
https://en.cppreference.com/w/cpp/algorithm/equal
*/
#include <algorithm>
#include <iostream>
#include <string_view>
constexpr bool is_palindrome(const std::string_view& s)
{
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}
void test(const std::string_view& s)
{
    std::cout << "\"" << s << "\" "
        << (is_palindrome(s) ? "is" : "is not")
        << " a palindrome\n";
}
int main()
{
    test("radar");
    test("hello");
}

