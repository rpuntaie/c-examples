/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_priority_queue_empty.exe ./cpp/container_priority_queue_empty.cpp && (cd ../_build/cpp/;./container_priority_queue_empty.exe)
https://en.cppreference.com/w/cpp/container/priority_queue/empty
*/
#include <algorithm>
#include <iostream>
#include <queue>
int main()
{
    std::cout << std::boolalpha;
    std::priority_queue<int> container;
    std::cout << "Initially, container.empty(): " << container.empty() << '\n';
    container.push(42);
    std::cout << "After adding elements, container.empty(): " << container.empty() << '\n';
}

