/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_clear.exe ./cpp/container_unordered_map_clear.cpp && (cd ../_build/cpp/;./container_unordered_map_clear.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/clear
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
int main()
{
    std::unordered_map<int, char> container{{1, 'x'}, {2, 'y'}, {3, 'z'}};
    auto print = [](std::pair<const int, char>& n) { 
        std::cout << " " << n.first << '(' << n.second << ')'; 
    };
    std::cout << "Before clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << '\n';
    std::cout << "Clear\n";
    container.clear();
    std::cout << "After clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << '\n';
}

