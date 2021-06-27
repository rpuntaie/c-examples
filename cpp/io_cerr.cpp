/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_cerr.exe ./cpp/io_cerr.cpp && (cd ../_build/cpp/;./io_cerr.exe)
https://en.cppreference.com/w/cpp/io/cerr
*/
#include <thread>
#include <iostream>
#include <chrono>
void f()
{
    std::cout << "Output from thread...";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "...thread calls flush()" << std::endl;
}
int main()
{
    std::thread t1(f);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::clog << "This output from main is not tie()'d to cout\n";
    std::cerr << "This output is tie()'d to cout\n";
    t1.join();
}

