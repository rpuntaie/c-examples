/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_back.exe ./cpp/container_deque_back.cpp && (cd ../_build/cpp/;./container_deque_back.exe)
https://en.cppreference.com/w/cpp/container/deque/back
*/
#include <deque>
#include <iostream>
int main()
{
    std::deque<char> letters {'a', 'b', 'c', 'd', 'e', 'f'};
    if (!letters.empty()) {
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }  
}

