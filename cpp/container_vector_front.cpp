/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_front.exe ./cpp/container_vector_front.cpp && (cd ../_build/cpp/;./container_vector_front.exe)
https://en.cppreference.com/w/cpp/container/vector/front
*/
#include <vector>
#include <iostream>
int main()
{
    std::vector<char> letters {'o', 'm', 'g', 'w', 't', 'f'};
    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    }  
}

