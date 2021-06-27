/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_max_size.exe ./cpp/container_list_max_size.cpp && (cd ../_build/cpp/;./container_list_max_size.exe)
https://en.cppreference.com/w/cpp/container/list/max_size
*/
#include <iostream>
#include <list>
int main()
{
    std::list<char> s;
    std::cout << "Maximum size of a 'list' is " << s.max_size() << "\n";
}

