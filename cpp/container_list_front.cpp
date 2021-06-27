/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_front.exe ./cpp/container_list_front.cpp && (cd ../_build/cpp/;./container_list_front.exe)
https://en.cppreference.com/w/cpp/container/list/front
*/
#include <list>
#include <iostream>
int main()
{
    std::list<char> letters {'o', 'm', 'g', 'w', 't', 'f'};
    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    }  
}

