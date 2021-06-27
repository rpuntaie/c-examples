/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_iota_1.exe ./cpp/algorithm_iota_1.cpp && (cd ../_build/cpp/;./algorithm_iota_1.exe)
https://en.cppreference.com/w/cpp/algorithm/iota
*/
#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>
int main()
{
    std::list<int> l(10);
    std::iota(l.begin(), l.end(), -4);
    std::vector<std::list<int>::iterator> v(l.size());
    std::iota(v.begin(), v.end(), l.begin());
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
    std::cout << "Contents of the list: ";
    for(auto n: l) std::cout << n << ' ';
    std::cout << '\n';
    std::cout << "Contents of the list, shuffled: ";
    for(auto i: v) std::cout << *i << ' ';
    std::cout << '\n';
}

