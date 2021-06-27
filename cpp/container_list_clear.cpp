/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_clear.exe ./cpp/container_list_clear.cpp && (cd ../_build/cpp/;./container_list_clear.exe)
https://en.cppreference.com/w/cpp/container/list/clear
*/
#include <algorithm>
#include <iostream>
#include <list>
int main()
{
    std::list<int> container{1, 2, 3};
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

