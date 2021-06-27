/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_max_size.exe ./cpp/container_unordered_map_max_size.cpp && (cd ../_build/cpp/;./container_unordered_map_max_size.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/max_size
*/
#include <iostream>
#include <unordered_map>
int main()
{
    std::unordered_map<char,char> s;
    std::cout << "Maximum size of an 'unordered_map' is " << s.max_size() << "\n";
}

