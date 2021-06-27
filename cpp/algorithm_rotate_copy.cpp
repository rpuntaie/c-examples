/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_rotate_copy.exe ./cpp/algorithm_rotate_copy.cpp && (cd ../_build/cpp/;./algorithm_rotate_copy.exe)
https://en.cppreference.com/w/cpp/algorithm/rotate_copy
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
int main()
{
    std::vector<int> src = {1, 2, 3, 4, 5}; 
    auto pivot = std::find(src.begin(), src.end(), 3); 
    std::vector<int> dest(src.size());                                          
    std::rotate_copy(src.begin(), pivot, src.end(), dest.begin());
    for (const auto &i : dest) {
        std::cout << i << ' ';
    }   
    std::cout << '\n';
    // copy the rotation result directly to the std::cout
    pivot = std::find(dest.begin(), dest.end(), 1);
    std::rotate_copy(dest.begin(), pivot, dest.end(),
                     std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

