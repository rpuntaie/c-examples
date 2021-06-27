/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_thread_id_operator_ltlt.exe ./cpp/thread_thread_id_operator_ltlt.cpp && (cd ../_build/cpp/;./thread_thread_id_operator_ltlt.exe)
https://en.cppreference.com/w/cpp/thread/thread/id/operator_ltlt
*/
#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono;
int main()
{
    std::thread t1([]{ std::this_thread::sleep_for(256ms); });
    std::thread t2([]{ std::this_thread::sleep_for(512ms); });
    std::clog << t1.get_id() << '\n' << t2.get_id() << '\n';
    t1.join(); t2.join();
}

