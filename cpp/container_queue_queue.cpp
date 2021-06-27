/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_queue_queue.exe ./cpp/container_queue_queue.cpp && (cd ../_build/cpp/;./container_queue_queue.exe)
https://en.cppreference.com/w/cpp/container/queue/queue
*/
#include <queue>
#include <deque>
#include <iostream>
int main()
{
    std::queue<int> c1;
    c1.push(5);
    std::cout << c1.size() << '\n';
    std::queue<int> c2(c1);
    std::cout << c2.size() << '\n';
    std::deque<int> deq {3, 1, 4, 1, 5};
    std::queue<int> c3(deq);
    std::cout << c3.size() << '\n';
}

