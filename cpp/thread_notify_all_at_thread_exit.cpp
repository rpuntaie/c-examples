/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_notify_all_at_thread_exit.exe ./cpp/thread_notify_all_at_thread_exit.cpp && (cd ../_build/cpp/;./thread_notify_all_at_thread_exit.exe)
https://en.cppreference.com/w/cpp/thread/notify_all_at_thread_exit
*/
#include <mutex>
#include <thread>
#include <condition_variable>
#include <cassert>
#include <string>
std::mutex m;
std::condition_variable cv;
bool ready = false;
std::string result; // some arbitrary type
void thread_func()
{
    thread_local std::string thread_local_data = "42";
    std::unique_lock<std::mutex> lk(m);
    // assign a value to result using thread_local data
    result = thread_local_data;
    ready = true;
    std::notify_all_at_thread_exit(cv, std::move(lk));
}   // 1. destroy thread_locals;
    // 2. unlock mutex;
    // 3. notify cv.
int main()
{
    std::thread t(thread_func);
    t.detach();
    // do other work
    // ...
    // wait for the detached thread
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{ return ready; });
    // result is ready and thread_local destructors have finished, no UB
    assert(result == "42");
}

