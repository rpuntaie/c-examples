/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_multimap_max_size.exe ./cpp/container_multimap_max_size.cpp && (cd ../_build/cpp/;./container_multimap_max_size.exe)
https://en.cppreference.com/w/cpp/container/multimap/max_size
*/
#include <iostream>
#include <map>
int main()
{
    std::multimap<char,char> s;
    std::cout << "Maximum size of a 'multimap' is " << s.max_size() << "\n";
}

