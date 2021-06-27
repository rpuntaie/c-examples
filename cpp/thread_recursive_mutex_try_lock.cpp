/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_recursive_mutex_try_lock.exe ./cpp/thread_recursive_mutex_try_lock.cpp && (cd ../_build/cpp/;./thread_recursive_mutex_try_lock.exe)
https://en.cppreference.com/w/cpp/thread/recursive_mutex/try_lock
*/
#include <iostream>
#include <mutex>
int main()
{
    std::recursive_mutex test;
    if (test.try_lock()) {
        std::cout << "lock acquired\n";
        test.unlock();
    } else {
        std::cout << "lock not acquired\n";
    }
    test.lock();
    // non-recursive mutex would return false from try_lock now
    if (test.try_lock()) {
        std::cout << "lock acquired\n";
        test.unlock(); 
    } else {
        std::cout << "lock not acquired\n";
    }
    test.unlock();
}

