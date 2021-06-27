/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multiset_size.exe ./cpp/container_unordered_multiset_size.cpp && (cd ../_build/cpp/;./container_unordered_multiset_size.exe)
https://en.cppreference.com/w/cpp/container/unordered_multiset/size
*/
#include <unordered_set>
#include <iostream>
int main()
{ 
    std::unordered_multiset<int> nums {1, 3, 5, 7};
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

