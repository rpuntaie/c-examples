/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_size.exe ./cpp/container_vector_size.cpp && (cd ../_build/cpp/;./container_vector_size.exe)
https://en.cppreference.com/w/cpp/container/vector/size
*/
#include <vector>
#include <iostream>
int main()
{ 
    std::vector<int> nums {1, 3, 5, 7};
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

