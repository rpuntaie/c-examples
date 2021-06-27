/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_max_size.exe ./cpp/container_deque_max_size.cpp && (cd ../_build/cpp/;./container_deque_max_size.exe)
https://en.cppreference.com/w/cpp/container/deque/max_size
*/
#include <iostream>
#include <deque>
int main()
{
    std::deque<char> s;
    std::cout << "Maximum size of a 'deque' is " << s.max_size() << "\n";
}

