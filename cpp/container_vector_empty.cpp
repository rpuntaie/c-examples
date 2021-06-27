/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_empty.exe ./cpp/container_vector_empty.cpp && (cd ../_build/cpp/;./container_vector_empty.exe)
https://en.cppreference.com/w/cpp/container/vector/empty
*/
#include <vector>
#include <iostream>
int main()
{
    std::cout << std::boolalpha;
    std::vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}

