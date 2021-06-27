/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_thread_joinable.exe ./cpp/thread_thread_joinable.cpp && (cd ../_build/cpp/;./thread_thread_joinable.exe)
https://en.cppreference.com/w/cpp/thread/thread/joinable
*/
#include <iostream>
#include <thread>
#include <chrono>
void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
int main()
{
    std::thread t;
    std::cout << "before starting, joinable: " << std::boolalpha << t.joinable()
              << '\n';
    t = std::thread(foo);
    std::cout << "after starting, joinable: " << t.joinable() 
              << '\n';
    t.join();
    std::cout << "after joining, joinable: " << t.joinable() 
              << '\n';
}

