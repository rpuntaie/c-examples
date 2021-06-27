/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_thread_swap2.exe ./cpp/thread_thread_swap2.cpp && (cd ../_build/cpp/;./thread_thread_swap2.exe)
https://en.cppreference.com/w/cpp/thread/thread/swap2
*/
#include <iostream>
#include <thread>
#include <chrono>
void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
void bar()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
int main()
{
    using std::swap;
    std::thread t1(foo);
    std::thread t2(bar);
    std::cout << "thread 1 id: " << t1.get_id() << '\n'
              << "thread 2 id: " << t2.get_id() << '\n';
    swap(t1, t2);
    std::cout << "after std::swap(t1, t2):" << '\n'
              << "thread 1 id: " << t1.get_id() << '\n'
              << "thread 2 id: " << t2.get_id() << '\n';
    t1.swap(t2);
    std::cout << "after t1.swap(t2):" << '\n'
              << "thread 1 id: " << t1.get_id() << '\n'
              << "thread 2 id: " << t2.get_id() << '\n';
    t1.join();
    t2.join();
}

