/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_assign.exe ./cpp/container_vector_assign.cpp && (cd ../_build/cpp/;./container_vector_assign.exe)
https://en.cppreference.com/w/cpp/container/vector/assign
*/
#include <vector>
#include <iostream>
#include <string>
int main()
{
    std::vector<char> characters;
    auto print_vector = [&](){
        for (char c : characters)
            std::cout << c << ' ';
        std::cout << '\n';  
    };
    characters.assign(5, 'a');
    print_vector();
    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print_vector();
    characters.assign({'C', '+', '+', '1', '1'});
    print_vector();
}

