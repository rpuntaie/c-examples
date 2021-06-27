/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_set_max_size.exe ./cpp/container_unordered_set_max_size.cpp && (cd ../_build/cpp/;./container_unordered_set_max_size.exe)
https://en.cppreference.com/w/cpp/container/unordered_set/max_size
*/
#include <iostream>
#include <unordered_set>
int main()
{
    std::unordered_set<char> s;
    std::cout << "Maximum size of an 'unordered_set' is " << s.max_size() << "\n";
}

