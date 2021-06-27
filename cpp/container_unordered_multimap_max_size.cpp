/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multimap_max_size.exe ./cpp/container_unordered_multimap_max_size.cpp && (cd ../_build/cpp/;./container_unordered_multimap_max_size.exe)
https://en.cppreference.com/w/cpp/container/unordered_multimap/max_size
*/
#include <iostream>
#include <unordered_map>
int main()
{
    std::unordered_multimap<char,char> s;
    std::cout << "Maximum size of an 'unordered_multimap' is " << s.max_size() << "\n";
}

