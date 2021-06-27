/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_stable_partition.exe ./cpp/algorithm_stable_partition.cpp && (cd ../_build/cpp/;./algorithm_stable_partition.exe)
https://en.cppreference.com/w/cpp/algorithm/stable_partition
*/
#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    std::vector<int> v{0, 0, 3, 0, 2, 4, 5, 0, 7};
    std::stable_partition(v.begin(), v.end(), [](int n){return n>0;});
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

