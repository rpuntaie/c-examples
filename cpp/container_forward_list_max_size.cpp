/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_forward_list_max_size.exe ./cpp/container_forward_list_max_size.cpp && (cd ../_build/cpp/;./container_forward_list_max_size.exe)
https://en.cppreference.com/w/cpp/container/forward_list/max_size
*/
#include <iostream>
#include <forward_list>
int main()
{
    std::forward_list<char> s;
    std::cout << "Maximum size of a 'forward_list' is " << s.max_size() << "\n";
}

