/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_setbuf_1.exe ./cpp/io_c_setbuf_1.cpp && (cd ../_build/cpp/;./io_c_setbuf_1.exe)
https://en.cppreference.com/w/cpp/io/c/setbuf
*/
#include <cstdio>
#include <thread>
#include <chrono>
int main()
{
    using namespace std::chrono_literals;
    std::setbuf(stdout, nullptr); // unbuffered stdout
    std::putchar('a'); // appears immediately on unbuffered stream
    std::this_thread::sleep_for(1s);
    std::putchar('b');
}

