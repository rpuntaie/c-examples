/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_thread_hardware_concurrency.exe ./cpp/thread_thread_hardware_concurrency.cpp && (cd ../_build/cpp/;./thread_thread_hardware_concurrency.exe)
https://en.cppreference.com/w/cpp/thread/thread/hardware_concurrency
*/
#include <iostream>
#include <thread>
int main() {
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
}

