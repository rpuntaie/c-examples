/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_stack_size.exe ./cpp/container_stack_size.cpp && (cd ../_build/cpp/;./container_stack_size.exe)
https://en.cppreference.com/w/cpp/container/stack/size
*/
#include <algorithm>
#include <iostream>
#include <stack>
int main()
{
    std::cout << std::boolalpha;
    std::stack<int> container;
    std::cout << "Initially, container.size(): " << container.size() << '\n';
    for (int i = 0; i < 7; ++i)
        container.push(i);
    std::cout << "After adding elements, container.size(): " << container.size() << '\n';
}

