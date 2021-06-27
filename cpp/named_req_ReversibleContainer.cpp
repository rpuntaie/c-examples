/*
g++ --std=c++20 -pthread -o ../_build/cpp/named_req_ReversibleContainer.exe ./cpp/named_req_ReversibleContainer.cpp && (cd ../_build/cpp/;./named_req_ReversibleContainer.exe)
https://en.cppreference.com/w/cpp/named_req/ReversibleContainer
*/
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    for(std::vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i) {
        std::cout << *i << '\n';
    }
}

