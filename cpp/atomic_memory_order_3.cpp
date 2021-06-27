/*
g++ --std=c++20 -pthread -o ../_build/cpp/atomic_memory_order_3.exe ./cpp/atomic_memory_order_3.cpp && (cd ../_build/cpp/;./atomic_memory_order_3.exe)
https://en.cppreference.com/w/cpp/atomic/memory_order
*/
#include <thread>
#include <atomic>
#include <cassert>
#include <vector>
std::vector<int> data;
std::atomic<int> flag = {0};
void thread_1()
{
    data.push_back(42);
    flag.store(1, std::memory_order_release);
}
void thread_2()
{
    int expected=1;
    while (!flag.compare_exchange_strong(expected, 2, std::memory_order_acq_rel)) {
        expected = 1;
    }
}
void thread_3()
{
    while (flag.load(std::memory_order_acquire) < 2)
        ;
    assert(data.at(0) == 42); // will never fire
}
int main()
{
    std::thread a(thread_1);
    std::thread b(thread_2);
    std::thread c(thread_3);
    a.join(); b.join(); c.join();
}

