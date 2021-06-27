/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_back.exe ./cpp/container_vector_back.cpp && (cd ../_build/cpp/;./container_vector_back.exe)
https://en.cppreference.com/w/cpp/container/vector/back
*/
#include <vector>
#include <iostream>
int main()
{
    std::vector<char> letters {'a', 'b', 'c', 'd', 'e', 'f'};
    if (!letters.empty()) {
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }  
}

