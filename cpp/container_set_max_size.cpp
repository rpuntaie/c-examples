/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_max_size.exe ./cpp/container_set_max_size.cpp && (cd ../_build/cpp/;./container_set_max_size.exe)
https://en.cppreference.com/w/cpp/container/set/max_size
*/
#include <iostream>
#include <set>
int main()
{
    std::set<char> s;
    std::cout << "Maximum size of a 'set' is " << s.max_size() << "\n";
}

