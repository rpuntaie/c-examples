/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_front.exe ./cpp/container_deque_front.cpp && (cd ../_build/cpp/;./container_deque_front.exe)
https://en.cppreference.com/w/cpp/container/deque/front
*/
#include <deque>
#include <iostream>
int main()
{
    std::deque<char> letters {'o', 'm', 'g', 'w', 't', 'f'};
    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    }  
}

