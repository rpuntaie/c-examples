/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_map_empty.exe ./cpp/container_map_empty.cpp && (cd ../_build/cpp/;./container_map_empty.exe)
https://en.cppreference.com/w/cpp/container/map/empty
*/
#include <map>
#include <iostream>
#include <utility>
int main()
{
    std::map<int,int> numbers;
    std::cout << std::boolalpha;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
    numbers.emplace(42, 13);
    numbers.insert(std::make_pair(13317, 123)); 
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}

