/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_move.exe ./cpp/algorithm_move.cpp && (cd ../_build/cpp/;./algorithm_move.exe)
https://en.cppreference.com/w/cpp/algorithm/move
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
    std::vector<std::thread> v;
    v.emplace_back(f, 1);
    v.emplace_back(f, 2);
    v.emplace_back(f, 3);
    std::list<std::thread> l;
    // copy() would not compile, because std::thread is noncopyable
    std::move(v.begin(), v.end(), std::back_inserter(l)); 
    for (auto& t : l) t.join();
}

