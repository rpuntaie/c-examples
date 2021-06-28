/*
g++ --std=c++20 -latomic -pthread -o ../_build/cpp/atomic_atomic_flag_test_and_set.exe ./cpp/atomic_atomic_flag_test_and_set.cpp && (cd ../_build/cpp/;./atomic_atomic_flag_test_and_set.exe)
https://en.cppreference.com/w/cpp/atomic/atomic_flag_test_and_set
*/
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
std::atomic_flag lock = ATOMIC_FLAG_INIT;
void f(int n)
{
    for (int cnt = 0; cnt < 100; ++cnt) {
        while(std::atomic_flag_test_and_set_explicit(&lock, std::memory_order_acquire))
             ; // spin until the lock is acquired
        std::cout << "Output from thread " << n << '\n';
        std::atomic_flag_clear_explicit(&lock, std::memory_order_release);
    }
}
int main()
{
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f, n);
    }
    for (auto& t : v) {
        t.join();
    }
}

