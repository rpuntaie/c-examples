/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_back.exe ./cpp/container_array_back.cpp && (cd ../_build/cpp/;./container_array_back.exe)
https://en.cppreference.com/w/cpp/container/array/back
*/
#include <array>
#include <iostream>
int main()
{
    std::array<char, 6> letters {'a', 'b', 'c', 'd', 'e', 'f'};
    if (!letters.empty()) {
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }  
}

