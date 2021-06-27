/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_forward_list_empty.exe ./cpp/container_forward_list_empty.cpp && (cd ../_build/cpp/;./container_forward_list_empty.exe)
https://en.cppreference.com/w/cpp/container/forward_list/empty
*/
#include <forward_list>
#include <iostream>
int main()
{
    std::forward_list<int> numbers;
    std::cout << std::boolalpha;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
    numbers.push_front(42);
    numbers.push_front(13317); 
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}

