/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multimap_emplace.exe ./cpp/container_unordered_multimap_emplace.cpp && (cd ../_build/cpp/;./container_unordered_multimap_emplace.exe)
https://en.cppreference.com/w/cpp/container/unordered_multimap/emplace
*/
#include <iostream>
#include <utility>
#include <string>
#include <unordered_map>
int main()
{
    std::unordered_multimap<std::string, std::string> m;
    // uses pair's move constructor
    m.emplace(std::make_pair(std::string("a"), std::string("a")));
    // uses pair's converting move constructor
    m.emplace(std::make_pair("b", "abcd"));
    // uses pair's template constructor
    m.emplace("d", "ddd");
    // uses pair's piecewise constructor
    m.emplace(std::piecewise_construct,
              std::forward_as_tuple("c"),
              std::forward_as_tuple(10, 'c'));
    for (const auto &p : m) {
        std::cout << p.first << " => " << p.second << '\n';
    }
}

