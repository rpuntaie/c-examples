/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_map_max_size.exe ./cpp/container_map_max_size.cpp && (cd ../_build/cpp/;./container_map_max_size.exe)
https://en.cppreference.com/w/cpp/container/map/max_size
*/
#include <iostream>
#include <map>
int main()
{
    std::map<char,char> s;
    std::cout << "Maximum size of a 'map' is " << s.max_size() << "\n";
}

