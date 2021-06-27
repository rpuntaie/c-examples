/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_size.exe ./cpp/container_deque_size.cpp && (cd ../_build/cpp/;./container_deque_size.exe)
https://en.cppreference.com/w/cpp/container/deque/size
*/
#include <deque>
#include <iostream>
int main()
{ 
    std::deque<int> nums {1, 3, 5, 7};
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

