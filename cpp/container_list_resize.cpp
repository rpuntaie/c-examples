/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_resize.exe ./cpp/container_list_resize.cpp && (cd ../_build/cpp/;./container_list_resize.exe)
https://en.cppreference.com/w/cpp/container/list/resize
*/
#include <iostream>
#include <list>
int main()
{
    std::list<int> c = {1, 2, 3};
    std::cout << "The list holds: ";
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

