/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_future_1.exe ./cpp/thread_future_1.cpp && (cd ../_build/cpp/;./thread_future_1.exe)
https://en.cppreference.com/w/cpp/thread/future
*/
#include <thread>
#include <iostream>
#include <future>
int main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread t([&p]{
        try {
            // code that may throw
            throw std::runtime_error("Example");
        } catch(...) {
            try {
                // store anything thrown in the promise
                p.set_exception(std::current_exception());
            } catch(...) {} // set_exception() may throw too
        }
    });
    try {
        std::cout << f.get();
    } catch(const std::exception& e) {
        std::cout << "Exception from the thread: " << e.what() << '\n';
    }
    t.join();
}

