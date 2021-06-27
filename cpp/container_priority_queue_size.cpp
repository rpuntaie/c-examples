/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_priority_queue_size.exe ./cpp/container_priority_queue_size.cpp && (cd ../_build/cpp/;./container_priority_queue_size.exe)
https://en.cppreference.com/w/cpp/container/priority_queue/size
*/
#include <algorithm>
#include <iostream>
#include <queue>
int main()
{
    std::cout << std::boolalpha;
    std::priority_queue<int> container;
    std::cout << "Initially, container.size(): " << container.size() << '\n';
    for (int i = 0; i < 7; ++i)
        container.push(i);
    std::cout << "After adding elements, container.size(): " << container.size() << '\n';
}

