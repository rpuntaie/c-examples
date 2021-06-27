/*
g++ --std=c++20 -pthread -o ../_build/cpp/atomic_memory_order_1.exe ./cpp/atomic_memory_order_1.cpp && (cd ../_build/cpp/;./atomic_memory_order_1.exe)
https://en.cppreference.com/w/cpp/atomic/memory_order
*/
#include <vector>
#include <iostream>
#include <thread>
#include <atomic>
std::atomic<int> cnt = {0};
void f()
{
    for (int n = 0; n < 1000; ++n) {
        cnt.fetch_add(1, std::memory_order_relaxed);
    }
}
int main()
{
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f);
    }
    for (auto& t : v) {
        t.join();
    }
    std::cout << "Final counter value is " << cnt << '\n';
}

