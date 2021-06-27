/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_erase.exe ./cpp/container_set_erase.cpp && (cd ../_build/cpp/;./container_set_erase.exe)
https://en.cppreference.com/w/cpp/container/set/erase
*/
#include <set>
#include <iostream>
int main()
{
    std::set<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // erase all odd numbers from c
    for(auto it = c.begin(); it != c.end(); ) {
        if(*it % 2 != 0)
            it = c.erase(it);
        else
            ++it;
    }
    for(int n : c) {
        std::cout << n << ' ';
    }
}

