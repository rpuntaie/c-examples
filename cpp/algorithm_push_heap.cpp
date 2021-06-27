/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_push_heap.exe ./cpp/algorithm_push_heap.cpp && (cd ../_build/cpp/;./algorithm_push_heap.exe)
https://en.cppreference.com/w/cpp/algorithm/push_heap
*/
#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
    std::make_heap(v.begin(), v.end());
    std::cout << "v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    v.push_back(6);
    std::cout << "before push_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    std::push_heap(v.begin(), v.end());
    std::cout << "after push_heap:  ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
}

