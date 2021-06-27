/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_resize.exe ./cpp/container_deque_resize.cpp && (cd ../_build/cpp/;./container_deque_resize.exe)
https://en.cppreference.com/w/cpp/container/deque/resize
*/
#include <iostream>
#include <deque>
int main()
{
    std::deque<int> c = {1, 2, 3};
    std::cout << "The deque holds: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(5);
    std::cout << "After resize up to 5: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for(auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
}

