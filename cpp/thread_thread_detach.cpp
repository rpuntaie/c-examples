/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_thread_detach.exe ./cpp/thread_thread_detach.cpp && (cd ../_build/cpp/;./thread_thread_detach.exe)
https://en.cppreference.com/w/cpp/thread/thread/detach
*/
#include <iostream>
#include <chrono>
#include <thread>
void independentThread() 
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exiting concurrent thread.\n";
}
void threadCaller() 
{
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";
}
int main() 
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

