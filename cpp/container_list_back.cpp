/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_back.exe ./cpp/container_list_back.cpp && (cd ../_build/cpp/;./container_list_back.exe)
https://en.cppreference.com/w/cpp/container/list/back
*/
#include <list>
#include <iostream>
int main()
{
    std::list<char> letters {'a', 'b', 'c', 'd', 'e', 'f'};
    if (!letters.empty()) {
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }  
}

