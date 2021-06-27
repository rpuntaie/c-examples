/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_assign.exe ./cpp/container_list_assign.cpp && (cd ../_build/cpp/;./container_list_assign.exe)
https://en.cppreference.com/w/cpp/container/list/assign
*/
#include <list>
#include <iostream>
#include <string>
int main()
{
    std::list<char> characters;
    auto print_list = [&](){
        for (char c : characters)
            std::cout << c << ' ';
        std::cout << '\n';  
    };
    characters.assign(5, 'a');
    print_list();
    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print_list();
    characters.assign({'C', '+', '+', '1', '1'});
    print_list();
}

