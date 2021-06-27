/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_future_error.exe ./cpp/thread_future_error.cpp && (cd ../_build/cpp/;./thread_future_error.exe)
https://en.cppreference.com/w/cpp/thread/future_error
*/
#include <future>
#include <iostream>
int main()
{
    std::future<int> empty;
    try {
        int n = empty.get(); // The behavior is undefined, but
                             // some implementations throw std::future_error
    } catch (const std::future_error& e) {
        std::cout << "Caught a future_error with code \"" << e.code()
                  << "\"\nMessage: \"" << e.what() << "\"\n";
    }
}

