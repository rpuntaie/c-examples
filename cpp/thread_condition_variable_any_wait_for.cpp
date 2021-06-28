/*
g++ --std=c++20 -latomic -pthread -o ../_build/cpp/thread_condition_variable_any_wait_for.exe ./cpp/thread_condition_variable_any_wait_for.cpp && (cd ../_build/cpp/;./thread_condition_variable_any_wait_for.exe)
https://en.cppreference.com/w/cpp/thread/condition_variable_any/wait_for
*/
#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
std::condition_variable_any cv;
std::mutex cv_m;
int i;
void waits(int idx)
{
    std::unique_lock<std::mutex> lk(cv_m);
    if(cv.wait_for(lk, idx*100ms, []{return i == 1;})) 
        std::cerr << "Thread " << idx << " finished waiting. i == " << i << '\n';
    else
        std::cerr << "Thread " << idx << " timed out. i == " << i << '\n';
}
void signals()
{
    std::this_thread::sleep_for(120ms);
    std::cerr << "Notifying...\n";
    cv.notify_all();
    std::this_thread::sleep_for(100ms);
    {
        std::lock_guard<std::mutex> lk(cv_m);
        i = 1;
    }
    std::cerr << "Notifying again...\n";
    cv.notify_all();
}
int main()
{
    std::thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

