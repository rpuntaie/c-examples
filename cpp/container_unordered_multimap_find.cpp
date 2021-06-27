/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multimap_find.exe ./cpp/container_unordered_multimap_find.cpp && (cd ../_build/cpp/;./container_unordered_multimap_find.exe)
https://en.cppreference.com/w/cpp/container/unordered_multimap/find
*/
#include <iostream>
#include <unordered_map>
int main()
{  
// simple comparison demo
    std::unordered_multimap<int,char> example = {{1,'a'},{2,'b'}};
    auto search = example.find(2);
    if (search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
    } else {
        std::cout << "Not found\n";
    }
}

