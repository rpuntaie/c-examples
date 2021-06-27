/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_set_clear.exe ./cpp/container_unordered_set_clear.cpp && (cd ../_build/cpp/;./container_unordered_set_clear.exe)
https://en.cppreference.com/w/cpp/container/unordered_set/clear
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
int main()
{
    std::unordered_set<int> container{1, 2, 3};
    auto print = [](const int& n) { std::cout << " " << n; };
    std::cout << "Before clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << '\n';
    std::cout << "Clear\n";
    container.clear();
    std::cout << "After clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << '\n';
}

