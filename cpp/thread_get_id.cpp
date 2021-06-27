/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_get_id.exe ./cpp/thread_get_id.cpp && (cd ../_build/cpp/;./thread_get_id.exe)
https://en.cppreference.com/w/cpp/thread/get_id
*/
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
std::mutex g_display_mutex;
void foo()
{
    std::thread::id this_id = std::this_thread::get_id();
    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping...\n";
    g_display_mutex.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}

