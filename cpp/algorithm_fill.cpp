/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_fill.exe ./cpp/algorithm_fill.cpp && (cd ../_build/cpp/;./algorithm_fill.exe)
https://en.cppreference.com/w/cpp/algorithm/fill
*/
#include <algorithm>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill(v.begin(), v.end(), -1);
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

