/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_stack_stack.exe ./cpp/container_stack_stack.cpp && (cd ../_build/cpp/;./container_stack_stack.exe)
https://en.cppreference.com/w/cpp/container/stack/stack
*/
#include <stack>
#include <deque>
#include <iostream>
int main()
{
    std::stack<int> c1;
    c1.push(5);
    std::cout << c1.size() << '\n';
    std::stack<int> c2(c1);
    std::cout << c2.size() << '\n';
    std::deque<int> deq {3, 1, 4, 1, 5};
    std::stack<int> c3(deq);
    std::cout << c3.size() << '\n';
}

