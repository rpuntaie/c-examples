/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_crend.exe ./cpp/ranges_crend.cpp && (cd ../_build/cpp/;./ranges_crend.exe)
https://en.cppreference.com/w/cpp/ranges/crend
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
int main()
{
    int a[] = {4, 6, -3, 9, 10};
    std::cout << "Array backwards: ";
    namespace ranges = std::ranges;
    ranges::copy(ranges::rbegin(a), ranges::rend(a),
                 std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nVector backwards: ";
    std::vector<int> v = {4, 6, -3, 9, 10};
    ranges::copy(ranges::rbegin(v), ranges::rend(v),
                 std::ostream_iterator<int>(std::cout, " "));
}

