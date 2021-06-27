/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_copy_backward.exe ./cpp/algorithm_copy_backward.cpp && (cd ../_build/cpp/;./algorithm_copy_backward.exe)
https://en.cppreference.com/w/cpp/algorithm/copy_backward
*/
#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> from_vector;
    for (int i = 0; i < 10; i++) {
        from_vector.push_back(i);
    }
    std::vector<int> to_vector(15);
    std::copy_backward(from_vector.begin(), from_vector.end(), to_vector.end());
    std::cout << "to_vector contains: ";
    for (auto i: to_vector) {
        std::cout << i << " ";
    }
 }

