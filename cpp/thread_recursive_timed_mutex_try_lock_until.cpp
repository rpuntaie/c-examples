/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_recursive_timed_mutex_try_lock_until.exe ./cpp/thread_recursive_timed_mutex_try_lock_until.cpp && (cd ../_build/cpp/;./thread_recursive_timed_mutex_try_lock_until.exe)
https://en.cppreference.com/w/cpp/thread/recursive_timed_mutex/try_lock_until
*/
#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
std::recursive_timed_mutex test_mutex;
void f()
{
    auto now=std::chrono::steady_clock::now();
    test_mutex.try_lock_until(now + std::chrono::seconds(10));
    std::cout << "hello world\n";
}
int main()
{
    std::lock_guard<std::recursive_timed_mutex> l(test_mutex);
    std::thread t(f);
    t.join();
}

