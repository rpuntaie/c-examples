/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_multiset_size.exe ./cpp/container_multiset_size.cpp && (cd ../_build/cpp/;./container_multiset_size.exe)
https://en.cppreference.com/w/cpp/container/multiset/size
*/
#include <set>
#include <iostream>
int main()
{ 
    std::multiset<int> nums {1, 3, 5, 7};
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

