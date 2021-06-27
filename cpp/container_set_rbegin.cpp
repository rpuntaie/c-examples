/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_rbegin.exe ./cpp/container_set_rbegin.cpp && (cd ../_build/cpp/;./container_set_rbegin.exe)
https://en.cppreference.com/w/cpp/container/set/rbegin
*/
#include <iostream>
#include <set>
int main()
{
    std::set<unsigned> rep{1, 2, 3, 4, 1, 2, 3, 4};
    for (auto it = rep.crbegin(); it != rep.crend(); ++it) {
        for (auto n = *it; n > 0; --n)
            std::cout << "⏼" << ' ';
        std::cout << '\n';
    }
}

