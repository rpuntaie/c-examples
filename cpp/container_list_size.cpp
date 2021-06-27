/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_size.exe ./cpp/container_list_size.cpp && (cd ../_build/cpp/;./container_list_size.exe)
https://en.cppreference.com/w/cpp/container/list/size
*/
#include <list>
#include <iostream>
int main()
{ 
    std::list<int> nums {1, 3, 5, 7};
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

