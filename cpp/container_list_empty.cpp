/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_empty.exe ./cpp/container_list_empty.cpp && (cd ../_build/cpp/;./container_list_empty.exe)
https://en.cppreference.com/w/cpp/container/list/empty
*/
#include <list>
#include <iostream>
int main()
{
    std::list<int> numbers;
    std::cout << std::boolalpha;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
    numbers.push_back(42);
    numbers.push_back(13317); 
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}

