/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multiset_max_size.exe ./cpp/container_unordered_multiset_max_size.cpp && (cd ../_build/cpp/;./container_unordered_multiset_max_size.exe)
https://en.cppreference.com/w/cpp/container/unordered_multiset/max_size
*/
#include <iostream>
#include <unordered_set>
int main()
{
    std::unordered_multiset<char> s;
    std::cout << "Maximum size of an 'unordered_multiset' is " << s.max_size() << "\n";
}

