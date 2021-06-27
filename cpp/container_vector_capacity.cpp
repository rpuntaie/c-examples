/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_capacity.exe ./cpp/container_vector_capacity.cpp && (cd ../_build/cpp/;./container_vector_capacity.exe)
https://en.cppreference.com/w/cpp/container/vector/capacity
*/
#include <iostream>
#include <vector>
int main()
{
    int sz = 200;
    std::vector<int> v1;
    auto cap = v1.capacity();
    std::cout << "initial capacity=" << cap << '\n';
    for (int n = 0; n < sz; ++n) {
        v1.push_back(n);
        if (cap != v1.capacity()) {
            cap = v1.capacity();
            std::cout << "new capacity=" << cap << '\n';
        }
    }
    std::cout << "final size=" << v1.size() << '\n';
    std::cout << "final capacity=" << v1.capacity() << '\n';
}

