/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_size.exe ./cpp/container_array_size.cpp && (cd ../_build/cpp/;./container_array_size.exe)
https://en.cppreference.com/w/cpp/container/array/size
*/
#include <array>
#include <iostream>
int main()
{ 
    std::array<int, 4> nums {1, 3, 5, 7};
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

