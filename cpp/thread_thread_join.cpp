/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_thread_join.exe ./cpp/thread_thread_join.cpp && (cd ../_build/cpp/;./thread_thread_join.exe)
https://en.cppreference.com/w/cpp/thread/thread/join
*/
#include <iostream>
#include <thread>
#include <chrono>
void foo()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
void bar()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
int main()
{
    std::cout << "starting first helper...\n";
    std::thread helper1(foo);
    std::cout << "starting second helper...\n";
    std::thread helper2(bar);
    std::cout << "waiting for helpers to finish..." << std::endl;
    helper1.join();
    helper2.join();
    std::cout << "done!\n";
}

