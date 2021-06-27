/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_max_size.exe ./cpp/container_vector_max_size.cpp && (cd ../_build/cpp/;./container_vector_max_size.exe)
https://en.cppreference.com/w/cpp/container/vector/max_size
*/
#include <iostream>
#include <vector>
int main()
{
    std::vector<char> s;
    std::cout << "Maximum size of a 'vector' is " << s.max_size() << "\n";
}

