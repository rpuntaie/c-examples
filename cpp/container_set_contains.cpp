/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_contains.exe ./cpp/container_set_contains.cpp && (cd ../_build/cpp/;./container_set_contains.exe)
https://en.cppreference.com/w/cpp/container/set/contains
*/
#include <iostream>
#include <set>
int main()
{
    std::set<int> example = {1, 2, 3, 4};
    for(int x: {2, 5}) {
        if(example.contains(x)) {
            std::cout << x << ": Found\n";
        } else {
            std::cout << x << ": Not found\n";
        }
    }
}

