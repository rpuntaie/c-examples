/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_max_size.exe ./cpp/container_array_max_size.cpp && (cd ../_build/cpp/;./container_array_max_size.exe)
https://en.cppreference.com/w/cpp/container/array/max_size
*/
#include <iostream>
#include <array>
int main()
{
    std::array<char, 10> s;
    std::cout << "Maximum size of the 'array' is " << s.max_size() << "\n";
}

