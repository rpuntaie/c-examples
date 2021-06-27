/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_set_find.exe ./cpp/container_unordered_set_find.cpp && (cd ../_build/cpp/;./container_unordered_set_find.exe)
https://en.cppreference.com/w/cpp/container/unordered_set/find
*/
#include <iostream>
#include <unordered_set>
int main()
{  
// simple comparison demo
    std::unordered_set<int> example = {1, 2, 3, 4};
    auto search = example.find(2);
    if (search != example.end()) {
        std::cout << "Found " << (*search) << '\n';
    } else {
        std::cout << "Not found\n";
    }
}

