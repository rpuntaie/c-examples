/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multimap_contains.exe ./cpp/container_unordered_multimap_contains.cpp && (cd ../_build/cpp/;./container_unordered_multimap_contains.exe)
https://en.cppreference.com/w/cpp/container/unordered_multimap/contains
*/
#include <iostream>
#include <unordered_map>
int main()
{
    std::unordered_multimap<int,char> example = {{1,'a'},{2,'b'}};
    for(int x: {2, 5}) {
        if(example.contains(x)) {
            std::cout << x << ": Found\n";
        } else {
            std::cout << x << ": Not found\n";
        }
    }
}

