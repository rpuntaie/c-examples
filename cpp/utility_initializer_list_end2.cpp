/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_initializer_list_end2.exe ./cpp/utility_initializer_list_end2.cpp && (cd ../_build/cpp/;./utility_initializer_list_end2.exe)
https://en.cppreference.com/w/cpp/utility/initializer_list/end2
*/
#include <iostream>
int main() 
{
    // range-based for uses std::begin and std::end to iterate
    // over a given range; in this case, it's an initializer list
    for (int i : {3, 1, 4, 1}) {
        std::cout << i << '\n';
    }
}

