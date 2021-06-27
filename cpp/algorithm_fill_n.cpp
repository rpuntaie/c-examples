/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_fill_n.exe ./cpp/algorithm_fill_n.cpp && (cd ../_build/cpp/;./algorithm_fill_n.exe)
https://en.cppreference.com/w/cpp/algorithm/fill_n
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
int main()
{
    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill_n(v1.begin(), 5, -1);
    std::copy(begin(v1), end(v1), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

