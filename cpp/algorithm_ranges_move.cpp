/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_move.exe ./cpp/algorithm_ranges_move.cpp && (cd ../_build/cpp/;./algorithm_ranges_move.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/move
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <thread>
#include <chrono>
void f(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "thread " << n << " ended" << std::endl;
}
int main()
{
    std::vector<std::jthread> v;
    v.emplace_back(f, 1);
    v.emplace_back(f, 2);
    v.emplace_back(f, 3);
    std::list<std::jthread> l;
    // ranges::copy() would not compile, because std::jthread is noncopyable
    std::ranges::move(v, std::back_inserter(l));
}

