/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_min_element.exe ./cpp/algorithm_min_element.cpp && (cd ../_build/cpp/;./algorithm_min_element.exe)
https://en.cppreference.com/w/cpp/algorithm/min_element
*/
#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v{3, 1, 4, 1, 5, 9};
    std::vector<int>::iterator result = std::min_element(v.begin(), v.end());
    std::cout << "min element at: " << std::distance(v.begin(), result);
}

