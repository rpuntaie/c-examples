/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_clear.exe ./cpp/container_vector_clear.cpp && (cd ../_build/cpp/;./container_vector_clear.exe)
https://en.cppreference.com/w/cpp/container/vector/clear
*/
#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> container{1, 2, 3};
    auto print = [](const int& n) { std::cout << " " << n; };
    std::cout << "Before clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
    std::cout << "Clear\n";
    container.clear();
    std::cout << "After clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
}

