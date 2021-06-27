/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multiset_contains.exe ./cpp/container_unordered_multiset_contains.cpp && (cd ../_build/cpp/;./container_unordered_multiset_contains.exe)
https://en.cppreference.com/w/cpp/container/unordered_multiset/contains
*/
#include <iostream>
#include <unordered_set>
int main()
{
    std::unordered_multiset<int> example = {1, 2, 3, 4};
    for(int x: {2, 5}) {
        if(example.contains(x)) {
            std::cout << x << ": Found\n";
        } else {
            std::cout << x << ": Not found\n";
        }
    }
}

