/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_back_inserter.exe ./cpp/iterator_back_inserter.cpp && (cd ../_build/cpp/;./iterator_back_inserter.exe)
https://en.cppreference.com/w/cpp/iterator/back_inserter
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::fill_n(std::back_inserter(v), 3, -1);
    for (int n : v)
        std::cout << n << ' ';
}

