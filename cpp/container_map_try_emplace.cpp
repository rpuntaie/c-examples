/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_map_try_emplace.exe ./cpp/container_map_try_emplace.cpp && (cd ../_build/cpp/;./container_map_try_emplace.exe)
https://en.cppreference.com/w/cpp/container/map/try_emplace
*/
#include <iostream>
#include <utility>
#include <string>
#include <map>
int main()
{
    using namespace std::literals;
    std::map<std::string, std::string> m;
    m.try_emplace("a", "a"s);
    m.try_emplace("b", "abcd");
    m.try_emplace("c", 10, 'c');
    m.try_emplace("c", "Won't be inserted");
    for (const auto &p : m) {
        std::cout << p.first << " => " << p.second << '\n';
    }
}

