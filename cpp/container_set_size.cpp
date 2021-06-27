/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_size.exe ./cpp/container_set_size.cpp && (cd ../_build/cpp/;./container_set_size.exe)
https://en.cppreference.com/w/cpp/container/set/size
*/
#include <set>
#include <iostream>
int main()
{ 
    std::set<int> nums {1, 3, 5, 7};
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

