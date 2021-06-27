/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_iter_swap.exe ./cpp/algorithm_iter_swap.cpp && (cd ../_build/cpp/;./algorithm_iter_swap.exe)
https://en.cppreference.com/w/cpp/algorithm/iter_swap
*/
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
template<class ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end)
{
    for (ForwardIt i = begin; i != end; ++i)
        std::iter_swap(i, std::min_element(i, end));
}
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-9, +9);
    std::vector<int> v;
    std::generate_n(back_inserter(v), 20, bind(dist, gen));
    std::cout << "Before sort: " << std::showpos;
    for(auto e : v) std::cout << e << ' ';
    selection_sort(v.begin(), v.end());
    std::cout << "\nAfter sort : ";
    for(auto e : v) std::cout << e << ' ';
    std::cout << '\n';
}

