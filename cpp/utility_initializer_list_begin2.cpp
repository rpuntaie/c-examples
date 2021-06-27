/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_initializer_list_begin2.exe ./cpp/utility_initializer_list_begin2.cpp && (cd ../_build/cpp/;./utility_initializer_list_begin2.exe)
https://en.cppreference.com/w/cpp/utility/initializer_list/begin2
*/
#include <iostream>
#include <initializer_list>
int main() 
{
    std::initializer_list<int> il = {3, 1, 4, 1};
    for(auto it = std::begin(il); it != std::end(il); ++it) {
        std::cout << *it << '\n';
    }
}

