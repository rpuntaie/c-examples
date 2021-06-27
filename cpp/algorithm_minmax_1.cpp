/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_minmax_1.exe ./cpp/algorithm_minmax_1.cpp && (cd ../_build/cpp/;./algorithm_minmax_1.exe)
https://en.cppreference.com/w/cpp/algorithm/minmax
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
int main()
{
    std::vector<int> v {3, 1, 4, 1, 5, 9, 2, 6}; 
    std::srand(std::time(0));
    std::pair<int, int> bounds = std::minmax(std::rand() % v.size(),
                                             std::rand() % v.size());
    std::cout << "v[" << bounds.first << "," << bounds.second << "]: ";
    for (int i = bounds.first; i < bounds.second; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

