/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_size.exe ./cpp/container_unordered_map_size.cpp && (cd ../_build/cpp/;./container_unordered_map_size.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/size
*/
#include <unordered_map>
#include <iostream>
int main()
{ 
    std::unordered_map<int,char> nums {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

