/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_sleep_for.exe ./cpp/thread_sleep_for.cpp && (cd ../_build/cpp/;./thread_sleep_for.exe)
https://en.cppreference.com/w/cpp/thread/sleep_for
*/
#include <iostream>
#include <chrono>
#include <thread>
int main()
{
    using namespace std::chrono_literals;
    std::cout << "Hello waiter\n" << std::flush;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2000ms);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "Waited " << elapsed.count() << " ms\n";
}

