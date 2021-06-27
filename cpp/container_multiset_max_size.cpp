/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_multiset_max_size.exe ./cpp/container_multiset_max_size.cpp && (cd ../_build/cpp/;./container_multiset_max_size.exe)
https://en.cppreference.com/w/cpp/container/multiset/max_size
*/
#include <iostream>
#include <set>
int main()
{
    std::multiset<char> s;
    std::cout << "Maximum size of a 'multiset' is " << s.max_size() << "\n";
}

