/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_recursive_mutex_lock.exe ./cpp/thread_recursive_mutex_lock.cpp && (cd ../_build/cpp/;./thread_recursive_mutex_lock.exe)
https://en.cppreference.com/w/cpp/thread/recursive_mutex/lock
*/
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
int g_num = 0;  // protected by g_num_mutex
std::mutex g_num_mutex;
void slow_increment(int id) 
{
    for (int i = 0; i < 3; ++i) {
        g_num_mutex.lock();
        ++g_num;
        std::cout << id << " => " << g_num << '\n';
        g_num_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
int main()
{
    std::thread t1(slow_increment, 0);
    std::thread t2(slow_increment, 1);
    t1.join();
    t2.join();
}

